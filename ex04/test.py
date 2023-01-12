import unittest
from matrix import Matrix, Vector

u = Vector([0, 0, 0])
u2 = Vector([1, 2, 3])
u3 = Vector([-1, -2])

class TestSum(unittest.TestCase):
    def test_vector_sum(self):
        v = Vector([1, 1, 1])
        self.assertEqual(v.sum(), 3)
        v = Vector([8, -1, 7])
        self.assertEqual(v.sum(), 8 - 1 + 7)
    
    # def test_vector_abs_sum(self):
    #     v = Vector([1, -1, 1])
    #     self.assertEqual(v.abs_sum(), 3)
    
    def test_Matrix_sum(self):
        m = Matrix([[1, 2, 3], [4, 5, 6]])
        self.assertEqual(m.sum(), 1+2+3+4+5+6)

class TestMax(unittest.TestCase):
    def test_vector_max(self):
        v = Vector([25, -25, 30])
        self.assertEqual(v.max(), 30)
        v = Vector([31, -25, 30])
        self.assertEqual(v.max(), 31)
        
    def test_Matrix_max(self):
        v = Matrix([[25, -25, 29], [2, 30, 20]])
        self.assertEqual(v.max(), 30)
        v = Matrix([[31, -25, 30], [8, -35, 2]])
        self.assertEqual(v.max(), 31)

class TestNorms(unittest.TestCase):
    # pass
    def test_eulidian_norm(self):
        self.assertEqual(u.norm(), 0)
        # print(u2.norm())
        # print(u3.norm())
        self.assertAlmostEqual(u2.norm(), 3.74165738)
        self.assertAlmostEqual(u3.norm(), 2.236067977)
    
    def test_manhatan_norm(self):
        self.assertEqual(u.norm_1(), 0)
        self.assertEqual(u2.norm_1(), 6)
        self.assertEqual(u3.norm_1(), 3)  
    
    def test_infinity_norm(self):
        self.assertEqual(u.norm_inf(), 0)
        self.assertEqual(u2.norm_inf(), 3)
        self.assertEqual(u3.norm_inf(), 2)



if __name__=="__main__":
    unittest.main()