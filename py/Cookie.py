import math
while True:
    try:
        r,x,y = [float(i) for i in input().split()]
    except:
        break
    if x**2+y**2 >= r**2:
        print("miss")
    else:
        p = math.sqrt(x**2+y**2)
        beta = 2*math.pi - 2*math.acos(p/r)
        L = beta*r**2/2 + p*math.sqrt(r**2-p**2)
        l = math.pi*r**2-L
        print(L,l)
