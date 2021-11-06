while True:
    line = input()
    if line == '0':
        break
    F = [float(i) for i in input().split()]
    R = [float(i) for i in input().split()]

    d = sorted([r / f for r in R for f in F])
    print("%.2f" % max([d[i+1] / d[i] for i in range(len(d)-1)]))
