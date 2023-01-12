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