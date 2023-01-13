import unittest
from matrix import Matrix, Vector

def check_matrix_res(m: Matrix, res: list):
    assert len(m) == m.shape[0]
    assert len(m) == len(res)
    for i in range(len(m)):
        assert len(m[i]) == m.shape[1]
        assert len(m[i]) == len(res[i])
        assert m[i].data == res[i]

class TestDotProduct(unittest.TestCase):
    # pass
    def test_dot(self):
        u = Vector([1., 1.])
        v = Vector([1., 1.])

        assert u.dot(v) == 2

        u = Vector([-1., 6.])
        v = Vector([3., 2.])

        assert u.dot(v) == 9

        u = Vector([0., 0.])
        v = Vector([1., 1.])

        assert u.dot(v) == 0

if __name__=="__main__":
    unittest.main()