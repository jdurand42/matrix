
class Matrix():
	'''
		A Matrix class
	'''
	# self.data = []
	# self.shape = ()
	def __init__(self, arg):
		self.data = []
		try:
			if isinstance(arg, list):
				# No params check like len of matrix to be exact
				# Check for only int and float ?
				self.data = arg
				self.shape = (len(arg), len(arg[0]))
				for el in self.data:
					for x in el:
						if isinstance(x, (float, int)) == False:
							raise TypeError("Error: Shape must be correct")
					if len(el) != self.shape[1]:
						raise TypeError("Error: Shape must be correct")
			elif isinstance(arg, tuple):
				self.shape = arg
				if len(arg) != 2 or arg[0] <= 0 or arg[1] <= 0:
					raise TypeError("Error: Shape must be correct: (m, n)")
				for i in range(0, arg[0]):
					b = []
					for j in range(0, arg[1]):
						b.append(0)
					self.data.append(b)
			else:
				raise TypeError("Error: invalid init parameter, must be tuple or list [[]]")
		except:
			raise TypeError("Error: incorrect parameters for Matrix")

	def __str__(self):
		return (f"{type(self)}\n{self.shape}\n{self.data}")

	def __add__(self, other):
		if isinstance(other, Matrix) == False:
			raise TypeError("Error: Invalid opperand")
		if other.shape != self.shape:
			raise TypeError("Error: Can only add matrix of the same dimensions")

		b = []
		for i in range(0, len(self.data)):
			b.append([])
			for j in range(0, len(self.data[i])):
				b[i].append(self.data[i][j] + other.data[i][j])
		return Matrix(b)

	def __radd__(self, other):
		if isinstance(other, Matrix) == False:
			raise TypeError("Error: Invalid opperand")
		if other.shape != self.shape:
			raise TypeError("Error: Can only add matrix of the same dimensions")
		return self.__add__(other)

	def __sub__(self, other):
		if isinstance(other, Matrix) == False:
			raise TypeError("Error: Invalid opperand")
		if other.shape != self.shape:
			raise TypeError("Error: Can only add matrix of the same dimensions")

		b = []
		for i in range(0, len(self.data)):
			b.append([])
			for j in range(0, len(self.data[i])):
				b[i].append(self.data[i][j] - other.data[i][j])
		return Matrix(b)

	def __rsub__(self, other):
		if isinstance(other, Matrix) == False:
			raise TypeError("Error: Invalid opperand")
		if other.shape != self.shape:
			raise TypeError("Error: Can only add matrix of the same dimensions")
		return other.__sub__(self)

	def __opscalar__(self, n, mult=True):
		b = []
		for i in range(0, len(self.data)):
			b.append([])
			for j in range(0, len(self.data[i])):
				if mult == True:
					b[i].append(self.data[i][j] * n)
				else:
					b[i].append(self.data[i][j] / n)
		return Matrix(b)

	def _mul_mat_mat(self, other):
		if self.shape[1] != other.shape[0]:
			raise TypeError("Error: Mat mat mul works only on (m * n) and (n * p) shapes")
		ret = Matrix((self.shape[0], other.shape[1]))
		for i in range(0, len(self.data)):
			for j in range(0, len(other.data[0])):
				for k in range(0, len(other.data)):
					ret.data[i][j] += self.data[i][k] * other.data[k][j]
		return ret

	def __mul__(self, other):
		if isinstance(other, (float, int)):
			return self.__opscalar__(other)
		elif isinstance(other, Matrix):
			return self._mul_mat_mat(other)
		else:
			raise TypeError("Error: Unsupported type in Matrix multiplication")

	def __rmul__(self, other):
		if isinstance(other, (float, int)):
			return self.__opscalar__(other)
		elif isinstance(other, Matrix):
			return other._mul_mat_mat(self)
		else:
			raise TypeError("Error: Unsupported type in Matrix multiplication")

	def __truediv__(self, other):
		if isinstance(other, (float, int)) == False:
			raise TypeError("Invalid opperand: Matrix div only works with scalars")
		return self.__opscalar__(other, mult=False)

	def __rtruediv__(self, other):
		if isinstance(other, (float, int)) == False:
			raise TypeError("Invalid opperand: Matrix div only works with scalars")
		b = []
		for i in range(0, len(self.data)):
			b.append([])
			for j in range(0, len(self.data[i])):
				b[i].append(other / self.data[i][j])
		return Matrix(b)
	
	def __repr__(self):
		return "Matix(<shape: tuple>)\nMatrix(<values: list>)"
	
	def T(self):
		new_shape = (self.shape[1], self.shape[0])
		t = []
		for i in range(0, new_shape[0]):
			b = []
			for j in range(0, new_shape[1]):
				b.append(0)
			t.append(b)

		for i in range(0, self.shape[0]):
			for j in range(0, self.shape[1]):
				t[j][i] = self.data[i][j]
		return Matrix(t)

class Vector(Matrix):
	def __init__(self, arg):
		try:
			if isinstance(arg, list):
				if len(arg) > 1:
					for el in arg:
						if len(el) > 1:
							raise TypeError("Error: vector must be of shpe (1 * n) or (n * 1)")
			elif isinstance(arg, tuple):
				if len(arg) != 2 or 1 not in arg:
					raise TypeError("Error: vector must be of shpe (1 * n) or (n * 1)")
			super().__init__(arg)
		except:
			raise TypeError("Error: Vector arg must be of the form [[]] and of shape (1 * n) or (n * 1)")

	def __add__(self, other):
		return Vector(super().__add__(other).data)

	def __radd__(self, other):
		return Vector(super().__radd__(other).data)

	def __sub__(self, other):
		return Vector(super().__sub__(other).data)

	def __rsub__(self, other):
		return Vector(super().__rsub__(other).data)

	def __mul__(self, other):
		r = super().__mul__(other).data
		try:
			return Vector(r)
		except:
			return Matrix(r)

	def __rmul__(self, other):
		r = super().__rmul__(other).data
		try:
			return Vector(r)
		except:
			return Matrix(r)
			

	def __truediv__(self, other):
		return Vector(super().__truediv__(other).data)
	
	def __rtruediv__(self, other):
		return Vector(super().__rtruediv__(other).data)
	
	def T(self):
		return Vector(super().T().data)

	def dot(self, other):
		if isinstance(other, Vector) == False:
			raise TypeError("Error: vector must match")
		if self.shape != other.shape:
			raise TypeError("Error: Shapes must match and be of (m * 1) form")
		res = 0
		if self.shape[1] == 1:
			for i in range(self.shape[0]):
				res += self.data[i][0] * other.data[i][0]
		elif self.shape[0] == 1:
			for i in range(self.shape[1]):
				res += self.data[0][i] * other.data[0][i]		
		return res