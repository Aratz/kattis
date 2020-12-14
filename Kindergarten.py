kids = [int(i) for i in input()]
D = [0,kids[:1].count(0),kids[:1].count(1),kids[:1].count(2)]
for kid in kids[1:]:
    if kid==0:
        D[1] += 1
        D[0] += D[3] + D[2]
    elif kid==1:
        D[2] += 1
        D[0] += D[3]
    else:
        D[3] += 1
print(D[0])
