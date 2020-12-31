while True:
    n = int(input())
    if not n:
        break
    sol = 1
    m = 0
    M = -1
    for i in range(n):
        w1,w2,c= input().split()
        c = int(c)
        if w1 == 'divisible':
            sol *= c if sol%c else 1
        elif w1 == 'greater':
            m = max(m,c)
        elif w1 == 'less':
            M = min(M if M!=-1 else 2**31,c)
    k=1
    if M==-1:
        print('infinite')
    else:
        ans = [sol*k for k in range(int(M/sol+1)) if sol*k>m and sol*k<M]
        if ans:
            print(*ans)
        else:
            print('none')
