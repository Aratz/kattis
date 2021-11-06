import math

def evaluate(p,x):
    return sum([c*x**i for i,c in enumerate(p)])

def degree(p):
    for i, c in enumerate(reversed(p)):
        if c:
            return len(p) - i - 1
    else:
        return 0

while True:
    try:
        pb = [float(i) for i in input().split()]
        pu = [float(i) for i in input().split()]
    except:
        break

    p = [u-b for (u,b) in zip(pu,pb)]
    pd = [p[1], 2*p[2], 3*p[3], 0]

    if degree(p) == 0:
        sol = 0
    elif degree(p) >= 1:
        m = min(evaluate(p, 0), evaluate(p, 1))
        M = max(evaluate(p, 0), evaluate(p, 1))
        sol = M - m
        if degree(p) == 2:
            x = -p[1]/(2*p[2])
            if x>=0 and x<=1:
                m = min(m, x)
                M = max(M, x)
        elif degree(p) == 3:
            delta = pd[1]**2 - 4*pd[0]*pd[2]
            if delta==0 and -pd[1]/(2*pd[2])>=0 and -pd[1]/(2*pd[2])<=1:
                m = min(m, evaluate(p, -pd[1]/(2*pd[2])))
                M = max(M, evaluate(p, -pd[1]/(2*pd[2])))
            elif delta>0:
                x1 = (-pd[1]-math.sqrt(delta))/(2*pd[2])
                x2 = (-pd[1]+math.sqrt(delta))/(2*pd[2])
                for x in (x1, x2):
                    if x>=0 and x<=1:
                        m = min(m, evaluate(p, x))
                        M = max(M, evaluate(p, x))
        sol = M - m
    print(sol)
