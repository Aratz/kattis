def compute_string(val, s):
    for c in s:
        if c == 'L':
            val = 2*val
        elif c == 'R':
            val = 2*val + 1
    return val

def compute_star(val, s):
    sp = s.partition('*')
    val = compute_string(val, sp[0])
    if sp[1] == '*':
        l = compute_star(2*val, sp[2])
        r = compute_star(2*val + 1, sp[2])
        p = compute_star(val, sp[2])
        return l + r + p
    else:
        return val

s = input()
s = s.replace('P', '')
print(compute_star(1, s))
