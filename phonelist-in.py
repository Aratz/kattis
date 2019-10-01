import numpy.random as npr
t = 40
N = 10000
print(t)
for _ in range(t):
    print(N)
    for _ in range(N):
        print(npr.randint(10**1, 10**11))
