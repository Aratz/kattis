n = int(input())
s = [input() for _ in range(n)]
last = 0
for i in range(n - 1):
    a, b = [int(v) - 1 for v in input().split()]
    s[a] += s[b]
    s[b] = ""

    last = a

print(s[last])
