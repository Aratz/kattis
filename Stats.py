t=1
while True:
    try:
        l = [int(i) for i in input().split()]
        l = l[1:]
    except:
        break
    print("Case %d:" % t,min(l),max(l),max(l)-min(l))
    t+=1
