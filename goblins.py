from random import randint
g = 100000
print(g)
for _ in range(g):
    print(randint(0, 10000), randint(0, 10000))
    #print(0, 0)

m = 20000
print(m)
for _ in range(m):
    print(randint(0, 10000), randint(0, 10000), randint(1, 100))
    #print(0, 0, 1)
