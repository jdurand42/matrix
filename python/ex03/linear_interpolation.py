from matrix import Vector, Matrix

def lerp(u, v, t):
    if isinstance(t, (float, int)) == False or t < 0 or t > 1:
        raise ValueError("T isn't the right format, must be float 0 <= t <= 1")
    return u + t * (v - u)
