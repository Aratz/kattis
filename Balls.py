import math
n = int(input())
for _ in range(n):
    D, d, s = [float(i) for i in input().split()]
    if D <= d:
        print(0)
    elif D <= 2*d:
        print(1)
    else:
        beta = 2*math.degrees(math.atan(d/(D-d)))
        alpha = 2*math.degrees(math.asin((s+d)/(D-d))) - beta
        print(math.floor(360./(alpha+beta)))
