M = int(input())
C = int(input())
print(1) #T
print(M, C)
for i in range(C):
    for j in range(i+1, C):
        print(i, j, i+j)
