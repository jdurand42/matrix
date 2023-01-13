from matrix import Vector

def linear_combination(u, coefs):
    if len(u) == 1:
        return u[0].scl(coefs[0])
    return u[0].scl(coefs[0]).add(linear_combination(u[1:], coefs[1:]))