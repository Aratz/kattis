import numpy.random as npr

for _ in range(10):
    n = 10000
    m = 20000
    q = 100
    s = 0

    print(n, m, q, s)
    for _ in range(m):
        u = npr.randint(0, n)
        v = npr.randint(0, n)
        if u == v:
            v = (v + 1)%n
        t_0, P, d = npr.randint(0, 1001, 3)
        print(u, v, t_0, P, d)

    for _ in range(q):
        print(npr.randint(0, n))
print(0, 0, 0, 0)
