class Vector:
    def __init__(self, vec) -> None:
        self.data = []
        try:
            assert isinstance(vec, list)
            for x in vec:
                assert isinstance(x, (float, int))
                self.data.append(float(x))
            self.size = len(vec)
        except:
            raise TypeError("Vector: __init__: Arg is invalid, must be list type")
    
    # def check_vector_input(self, *args, **kwargs)

    def size(self):
        return self.size
    
    def print(self):
        print(self.data)
    
    def reshape(self, m, n):
        try:
            assert isinstance((m, n), int)
        except:
            raise TypeError("Vector: reshape: shape must be a tuple of the form (m, n). Ex: (4, 2)")
        pass

    # Iterations

    def __len__(self):
        return self.size
    
    def __iter__(self):
        return iter(self.data)
    
    def __getitem__(self, i: int):
        if isinstance(i, int) == False:
            raise ValueError("Error: indice must be a int")
        return self.data[i]
    
    def __setitem__(self, i: int, value: float):
        if isinstance(i, int) == False:
            raise ValueError("Error: indice must be a int")
        if isinstance(value, (int, float)) == False:
            raise ValueError("Error, value must be a float")
        self.data[i] = float(value)
    
    # Ex00

    def add(self, v):
        for i in range(len(v)):
            self.data[i] += v[i]
        return self
    
    def sub(self, v):
        for i in range(len(v)):
            self.data[i] -= v[i]
        return self

    def scl(self, k):
        for i in range(len(self.data)):
            self.data[i] *= k
        return self
    
    # magic

    def __add__(self, v):
        l = lambda a, b: ([x + y for (x, y) in zip(a, b)])
        return Vector(l(self.data, v.data))

    def __radd__(self, v):
        l = lambda a, b: ([x + y for (x, y) in zip(a, b)])
        return Vector(l(v.data, self.data))
    
    def __sub__(self, v):
        l = lambda a, b: ([x - y for (x, y) in zip(a, b)])
        return Vector(l(self.data, v.data))
    
    def __rsub__(self, v):
        l = lambda a, b: ([x - y for (x, y) in zip(a, b)])
        return Vector(l(v.data, self.data))
    
    def __mul__(self, k):
        l = lambda a, k: ([x * k for x in a])
        return Vector(l(self.data, k))
    
    def __rmul__(self, k):
        l = lambda a, k: ([x * k for x in a])
        return Vector(l(self.data, k))


class Matrix:
    def __init__(self, arg) -> None:
        try:
            assert isinstance(arg, list)
            self.data = []
            self.shape = (len(arg), len(arg[0]))
            for el in arg:
                for x in el:
                    if isinstance(x, (float, int)) == False:
                        raise TypeError("Error: Shape must be correct")
                    if len(el) != self.shape[1]:
                        raise TypeError("Error: Shape must be correct")
                if isinstance(el, list):
                    self.data.append(Vector(el))
                elif isinstance(el, Vector):
                    self.data.append(Vector(el.data))
                else:
                    raise Exception("Bad arguments")
        except:
            raise TypeError("Matrix: __init__: Arg is invalid, must be list of list type")

    def shape(self):
        return self.shape
    
    def issquare(self):
        return self.shape[0] == self.shape[1]
    
    def print(self):
        for el in self.data:
            el.print()
    
    def reshape(self, m, n):
        try:
            assert isinstance((m, n), int)
        except:
            raise TypeError("Vector: reshape: shape must be a tuple of the form (m, n). Ex: (4, 2)")
        pass

    def add(self, m):
        for i in range(len(self.data)):
            self.data[i].add(m.data[i])
        return self

    def sub(self, m):
        for i in range(len(self.data)):
            self.data[i].sub(m.data[i])
        return self

    def scl(self, k):
        for i in range(len(self.data)):
            self.data[i].scl(k)
        return self
    
    # Iter

    def __len__(self):
        return self.shape[0]
    
    def __iter__(self):
        return iter(self.data)
    
    def __getitem__(self, i: int):
        if isinstance(i, int) == False:
            raise ValueError("Error: indice must be a int")
        return self.data[i]
    
    def __setitem__(self, i: int, value):
        if isinstance(i, int) == False:
            raise ValueError("Error: indice must be a int")
        if isinstance(value, (Vector, list)) == False:
            raise ValueError("Error, value must be a Vector or a list")
        if len(value) != self.shape[1]:
            raise ValueError(f"Error: value len must be for form {self.shape[1]}")
        if isinstance(value, Vector):
            self.data[i] = Vector(value.data)
        else:
            self.data[i] = Vector(value)

    #  Magic

    def __add__(self, m):
        l = lambda a, b: ([x + y for (x, y) in zip(a, b)])
        return Matrix(l(self.data, m.data))

    def __radd__(self, m):
        l = lambda a, b: ([x + y for (x, y) in zip(a, b)])
        return Matrix(l(m.data, self.data))
    
    def __sub__(self, m):
        l = lambda a, b: ([x - y for (x, y) in zip(a, b)])
        return Matrix(l(self.data, m.data))
    
    def __rsub__(self, m):
        l = lambda a, b: ([x - y for (x, y) in zip(a, b)])
        return Matrix(l(m.data, self.data))
    
    def __mul__(self, k):
        l = lambda a, k: ([x * k for x in a])
        return Matrix(l(self.data, k))
    
    def __rmul__(self, k):
        l = lambda a, k: ([x * k for x in a])
        return Matrix(l(self.data, k))