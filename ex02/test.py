import unittest
from matrix import Matrix, Vector
from linear_interpolation import lerp

def check_matrix_res(m: Matrix, res: list):
    assert len(m) == m.shape[0]
    assert len(m) == len(res)
    for i in range(len(m)):
        assert len(m[i]) == m.shape[1]
        assert len(m[i]) == len(res[i])
        assert m[i].data == res[i]

class TestLinearInerpolation(unittest.TestCase):
    def test_linear_interpolation_float(self):
        assert lerp(0, 1, 0) == 0
        assert lerp(0, 1, 1) == 1
        assert lerp(0, 1, 0.5) == 0.5
        # print(lerp(21, 42, 0.3))
        assert lerp(21, 42, 0.3) == 27.3
 
    def test_on_vectors(self):
        a = lerp(Vector([2., 1.]), Vector([4., 2.]), 0.3)
        assert isinstance(a, Vector)
        assert a.data == [2.6, 1.3]
        
        a = lerp(Matrix([[2., 1.], [3., 4.]]), Matrix([[20.,10.], [30., 40.]]), 0.5)
        assert isinstance(a, Matrix)
        check_matrix_res(a, [[11, 5.5], [16.5, 22]])

if __name__=="__main__":
    unittest.main()