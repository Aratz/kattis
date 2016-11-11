s = input()
val = (1, 1)
for c in s:
    if c == 'L':
        val = (2*val[0], val[1])
    elif c == 'R':
        val = (2*val[0] + val[1], val[1])
    elif c == '*':
        val = (5*val[0] + val[1], 3*val[1])
print(val[0])
