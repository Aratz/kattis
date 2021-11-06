import math
class Player:
    def __init__(self,x,y,r):
        self.x = x
        self.y = y
        self.r = r
    def __equal__(self,other):
        return self.x==other.x and self.y==other.y and self.r==other.r
    def __repr__(self):
        return str((self.x,self.y,self.r))

def dist(p1,p2):
    return math.sqrt((p1.x-p2.x)**2+(p1.y-p2.y)**2)

n = int(input())
players = [Player(0,-1,0), Player(0,1001,0)]
edges = []
for i in range(n):
    players += [Player(*[float(i) for i in input().split()])]
for i,p1 in enumerate(players):
    if i==0 or i==1:
        continue
    if p1.y <= p1.r:
        edges += [(0,i)]
    if p1.y + p1.r >= 1000:
        edges += [(1,i)]
    for j,p2 in enumerate(players):
        if j<=i:
            continue
        if p1.r + p2.r >= dist(p1,p2):
            edges += [(min(i,j),max(i,j))]

groupList = [i for i in range(len(players))]
def find(i):
    if groupList[i]==i:
        return i
    else:
        return find(groupList[i])

for (i,j) in edges:
    groupList[find(j)]=find(i)

for i,p in enumerate(groupList):
    groupList[i] = find(i)

if groupList[0] == groupList[1]:
    print("IMPOSSIBLE")
else:
    entry = (0,1000)
    exit = (1000,1000)
    for i,g in enumerate(groupList):
        if i<2:
            continue
        if g==groupList[1]:
            p = players[i]
            if p.x<=p.r and p.y-math.sqrt(p.r**2-p.x**2)<entry[1]:
                entry = (0,p.y-math.sqrt(p.r**2-p.x**2))
            if p.x+p.r>=1000 and p.y-math.sqrt(p.r**2-(1000-p.x)**2)<exit[1]:
                exit = (1000,p.y-math.sqrt(p.r**2-(1000-p.x)**2))
    ans = ["%.2f" % s for s in [entry[0],entry[1],exit[0],exit[1]]]
    print(*ans)
                
            
