import numpy.random as npr
h, w = 140, 120
a, b = 1, h * w

print(h, w)
print(a, b)
for _ in range(h):
    print(*npr.randint(0, 10, w).tolist())

