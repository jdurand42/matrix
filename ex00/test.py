import unittest
from matrix import Matrix, Vector

class TestVector(unittest.TestCase):
    def test_init(self):
        v = Vector([1 , 2, 3])
        v2 = Vector([3, 4, 5, 6])
        assert v.size == 3
        assert v2.size == 4
        v = Vector([1.1 , 2.1, 3.2])
        v2 = Vector([3, 4, 5.5, 6.1])
        assert v.size == 3
        assert v2.size == 4

        v = Vector([])
        assert v.size == 0

    def test_iterations(self):
        v = Vector([1., 1., 1.])
        # v.print()
        assert len(v) == 3
        for i in range(len(v)):
            assert v[i] == 1.
            v[i] = 2.
        for i in range(0, len(v)):
            assert v[i] == 2.
    
    def test_init_errors(self):
        with self.assertRaises(TypeError):
            v = Vector((1, 2, 3))
        with self.assertRaises(TypeError):
            v = Vector(12)
        with self.assertRaises(TypeError):
            v = Vector(['n', 1.1, 2.5])
        with self.assertRaises(TypeError):
            v = Vector("salut")


class TestMatrix(unittest.TestCase):
    def test_init(self):
        m = Matrix([[1, 2.2, 3.]])
        assert m.shape == (1, 3)


        for el in m.data:
            assert isinstance(el, Vector)

        m = Matrix([[1. , 2.], [2., 4.]])
        assert m.shape == (2, 2)


        for el in m.data:
            assert isinstance(el, Vector)

        m = Matrix([[]])
        assert m.shape == (1, 0)
        m = Matrix([Vector([1.]), Vector([2.])])


        for el in m.data:
            assert isinstance(el, Vector)


    def test_init_errors(self):
        with self.assertRaises(TypeError):
            m = Matrix([1., 2., 3.])
        with self.assertRaises(TypeError):
            m = Matrix([[1., 2.], [2.]])
        with self.assertRaises(TypeError):
            m = Matrix([[1., 2.], ['a', 3.]])
        with self.assertRaises(TypeError):
            m = Matrix("dasd")
        with self.assertRaises(TypeError):
            m = Matrix((1., 2.), (1., 2.))

    def test_basic_methods(self):
        m = Matrix([[1, 2], [2, 4]])
        assert m.issquare()
        m.print()
        m = Matrix([[1, 2, 3], [1, 2, 3]])
        assert m.issquare() == False
        m.print()


class TestBasicVectorOperations(unittest.TestCase):
    def test_add(self):
        v = Vector([1, 2, 3])
        v2 = Vector([10.5, 10.5, 10.5])

        v.add(v2)
        assert v.size == 3
        assert v.data == [11.5, 12.5, 13.5]

    def test_sub(self):
        v = Vector([1, 2, 3])
        v2 = Vector([1, 1, 1])

        v.sub(v2)
        assert v.size == 3
        assert v.data == [0, 1, 2]
    
    def test_scl(self):
        v = Vector([1, 2, 3])
        # v2 = Vector([1, 1, 1])

        v.scl(2)
        v.print()
        assert v.size == 3
        assert v.data == [2, 4, 6]

class TestBasicMatrixOperations(unittest.TestCase):
    def test_add(self):
        v = Matrix([[1, 2, 3], [3, 2, 1]])
        v2 = Matrix([[10.5, 10.5, 10.5], [10.5, 10.5, 10.5]])

        v.add(v2)
        # v.print()
        # print(v.data)
        assert v.shape == (2, 3)
        assert v.data[0].data == [11.5, 12.5, 13.5]
        assert v.data[1].data == [13.5, 12.5, 11.5]

    def test_sub(self):
        v = Matrix([[1, 2, 3], [3, 2, 1]])
        v2 = Matrix([[1, 1, 1], [2, 2, 2]])

        v.sub(v2)
        # v.print()
        assert v.shape == (2, 3)
        assert v.data[0].data == [0, 1, 2]
        assert v.data[1].data ==  [1, 0, -1]
    
    def test_scl(self):
        v = Matrix([[1, 2, 3], [4, 5, 6]])
        # v2 = Matrix([1, 1, 1])

        v.scl(2)
        # v.print()
        assert v.shape == (2, 3)
        assert v.data[0].data == [2, 4, 6]
        assert v.data[1].data == [8, 10, 12]

class TestVectorMagicMethods(unittest.TestCase):
    def test_add_radd(self):
        v = Vector([1.5, 2.5, 3.5])
        v2 = Vector([0.5, 0, 2])

        v3 = v + v2
        assert v3.data == [2, 2.5, 5.5]
        assert v3.size == 3
        assert v.data == [1.5, 2.5, 3.5]
        assert v2.data == [0.5, 0, 2]
        assert (v2 + v).data == [2, 2.5, 5.5]
        assert (v2 + v).size == 3
        assert v.data == [1.5, 2.5, 3.5]
        assert v2.data == [0.5, 0, 2]
    
    def test_sub_rsub(self):
        v = Vector([1, 2, 3.5])
        v2 = Vector([1, 1.5, 2])

        v3 = v - v2
        assert v3.data == [0, 0.5, 1.5]
        assert v3.size == 3
        assert v.data == [1, 2, 3.5]
        assert v2.data == [1, 1.5, 2]

        v3 = v2 - v
        assert v3.data == [0, 1.5 - 2, 2 - 3.5]
        assert v3.size == 3
        assert v.data == [1, 2, 3.5]
        assert v2.data == [1, 1.5, 2]
    
    def test_mul_rmul(self):
        v = Vector([0.5, 2., 4, 8])

        v3 = v * 2
        assert v3.data == [1, 4, 8, 16]
        assert v.data == [0.5, 2., 4, 8]
        assert v.size == 4

        v3 = 2 * v
        assert v3.data == [1, 4, 8, 16]
        assert v.data == [0.5, 2., 4, 8]
        assert v.size == 4

if __name__=="__main__":
    unittest.main()