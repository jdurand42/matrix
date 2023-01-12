import unittest
from matrix import Matrix, Vector
from linear_combination import linear_combination

class TestLinearCombination(unittest.TestCase):
    def test_linear_combination(self):
        e1 = Vector([1., 0., 0.])
        e2 = Vector([0., 1., 0.])
        e3 = Vector([0., 0., 1.])
        v1 = Vector([1., 2., 3.])
        v2 = Vector([0., 10., -100.])

        assert linear_combination([e1, e2, e3], [10., -2., 0.5]).data == [10, -2, 0.5]
        assert linear_combination([v1, v2], [10., -2]).data == [10, 0, 230]
 
if __name__=="__main__":
    unittest.main()