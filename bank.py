N, T = [int(v) for v in input().split()]

schedule = [0 for t in range(T+1)]
clients = sorted([
        (int(c_i), int(t_i))
        for c_i, t_i in [[int(v) for v in input().split()] for _ in range(N)]
        ], key=lambda client: -client[0])

served = 0

for c, t in clients:
    while t >= 0 and schedule[t] > 0:
        t -= 1

    if t < 0:
        continue

    schedule[t] = c
    served += 1

    if served == T:
        break

print(sum(schedule))
