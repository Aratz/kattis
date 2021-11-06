while True:
    n,d = [int(i) for i in input().split()]
    if not n*d:
        break
    print(n//d,n%d,'/',d)
