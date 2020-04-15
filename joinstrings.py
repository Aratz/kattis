n = int(input())
s = [input() for _ in range(n)]
for i in range(n - 1):
    a, b = [int(v) - 1 for v in input().split()]
    s[a] += s[b]
    s[b] = ""

    if i == n - 2:
        print(s[a])
