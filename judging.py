n = int(input())
judge1 = {}
judge2 = {}
for i in range(n):
    ans = input()
    judge1[ans] = (judge1[ans] if ans in judge1 else 0) + 1
for i in range(n):
    ans = input()
    judge2[ans] = (judge2[ans] if ans in judge2 else 0) + 1
res = 0
for ans in judge1:
    if ans in judge2:
        res += min(judge1[ans], judge2[ans])
print(res)
