n = 1000
k = 500
print(n,k)
import random
#l = [random.randint(1,n) for _ in range(n)]
l = [(i+1)%n + 1 for i in range(n)]
print(*l)
