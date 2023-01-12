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

    def test_iterations(self):
        m = Matrix([[1, 1, 1, 1], [2, 2, 2, 2], [3, 3, 3, 3]])
        
        assert len(m) == 3
        assert len(m) == m.shape[0]
        assert m.shape[1] == 4
        for i in range(len(m)):
            assert len(m[i]) == 4
            assert isinstance(m[i], Vector)
            assert m[i].data == [i+1, i+1, i+1, i+1]
            m[i] = [i, i, i, i]
        
        assert len(m) == 3
        assert len(m) == m.shape[0]
        assert m.shape[1] == 4
        for i in range(len(m)):
            assert len(m[i]) == 4
            assert isinstance(m[i], Vector)
            assert m[i].data == [i, i, i, i]
            m[i] = Vector([i+2, i+2, i+2, i+2])
        
        assert len(m) == 3
        assert len(m) == m.shape[0]
        assert m.shape[1] == 4
        for i in range(len(m)):
            assert len(m[i]) == 4
            assert isinstance(m[i], Vector)
            assert m[i].data == [i+2, i+2, i+2, i+2]
        
        with self.assertRaises(ValueError):
            m[0] = [0, 0, 0]
        
        with self.assertRaises(ValueError):
            m[0] = "dsdass"
        
        with self.assertRaises(ValueError):
            m[0] = Vector([0])

    def test_basic_methods(self):
        m = Matrix([[1, 2], [2, 4]])
        assert m.issquare()
        m.print()
        m = Matrix([[1, 2, 3], [1, 2, 3]])
        assert m.issquare() == False
        m.print()


class TestVectorBasicOperations(unittest.TestCase):
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

def check_matrix_res(m: Matrix, res: list):
    assert len(m) == m.shape[0]
    assert len(m) == len(res)
    for i in range(len(m)):
        assert len(m[i]) == m.shape[1]
        assert len(m[i]) == len(res[i])
        assert m[i].data == res[i]


class TestMatrixBasicOperations(unittest.TestCase):
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

class TestMatrixMagicMethods(unittest.TestCase):
    def test_add_radd(self):
        m = Matrix([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
        m2 = Matrix([[-1, -2, -3], [-4, -5, -6], [-7, -8, -9]])
        res = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

        check_matrix_res(m + m2, res)
        check_matrix_res(m2 + m, res)
    
    def test_sub_rsub(self):
        m = Matrix([[1, 2, 3], [10, 11, 12]])
        m2 = Matrix([[1, 1, 2], [9, 10, 12]])
        res1 = [[0, 1, 1], [1, 1, 0]]
        res2 = [[0, -1, -1], [-1, -1, 0]]

        check_matrix_res(m - m2, res1)
        check_matrix_res(m2 - m, res2)
    
    def check_mul_rmul(self):
        m = Matrix([[0, 1, 2], [2, 1, 0]])
        k = 4
        res = [[0, 4, 8], [8, 4, 0]]

        check_matrix_res(m * k, res)
        check_matrix_res(k * m, res)

if __name__=="__main__":
    unittest.main()