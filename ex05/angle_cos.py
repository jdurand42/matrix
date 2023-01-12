from matrix import Vector
import ctypes
import numpy as np

def angle_cos(u: Vector, v: Vector):
    return np.float32(u.dot(v) / np.float32((u.norm() * v.norm())))