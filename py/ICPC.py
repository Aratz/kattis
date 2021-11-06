import math

def fact(n):
    if n==0 or n==1:
        return 1
    else:
        return n*fact(n-1)

d = {
        1:lambda x:fact(x),
        2:lambda x:2**x,
        3:lambda x:x**4,
        4:lambda x:x**3,
        5:lambda x:x**2,
        6:lambda x:x*math.log(x,2),
        7:lambda x:x,
    }
m,n,t = [int(i) for i in input().split()]
if t == 1:
    if n>=14 or m<d[t](n):
        print("TLE")
    else:
        print("AC")
elif t==2:
    if n>=40 or m<d[t](n):
        print("TLE")
    else:
        print("AC")
else:
    if m >= d[t](n):
        print("AC")
    else:
        print("TLE")
