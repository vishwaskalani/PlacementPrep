class Counter:
	def __init__(self,max_count):
		self.max_count = max_count
		self.current_count = 0

	def __iter__(self):
		return self

	def __next__(self):
		if self.current_count < self.max_count:
			self.current_count += 1
			return self.current_count
		else:
			raise StopIteration

counter = Counter(5)
for i in counter:
	print(i)

class SquaresUptilN:
	def __init__(self,n):
		self.n = n
		self.current = 0

	def __iter__(self):
		return self

	def __next__(self):
		if self.current < self.n:
			self.current += 1
			return self.current**2
		else:
			raise StopIteration

squares = SquaresUptilN(5)
for i in squares:
	print(i)