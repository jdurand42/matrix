import unittest
from matrix import Matrix, Vector
from angle_cos import angle_cos

u1 = Vector([1., 0.])
v1 = Vector([1., 0.])
u2 = Vector([1., 0.])
v2 = Vector([0., 1.])
u3 = Vector([-1., 1.])
v3 = Vector([ 1., -1.])
u4 = Vector([2., 1.])
v4 = Vector([4., 2.])
u5 = Vector([1., 2., 3.])
v5 = Vector([4., 5., 6.])

class TestCosine(unittest.TestCase):
    def test_cosinus(self):
        self.assertEqual(angle_cos(u1, v1), 1)
        self.assertEqual(angle_cos(u2, v2), 0)
        self.assertEqual(angle_cos(u3, v3), -1)
        self.assertEqual(angle_cos(u4, v4), 1)
        self.assertEqual(angle_cos(u5, v5), 0.974631846)


if __name__=="__main__":
    unittest.main()