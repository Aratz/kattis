from math import log

M = int(input())
N = int(log(M + 1)/log(2))

if M == 1:
    res = 0b1
elif M == 2:
    res = 0b11
elif M - 2**N + 1 < 2**(N-1) :
    p = '1' + "{:b}".format(M - 2**N + 1).zfill(N-1)
    res = int(p + p[-2::-1], 2)
else:
    p = '1' + "{:b}".format(M - 2**N - 2**(N-1) + 1).zfill(N-1)
    res = int(p + p[::-1], 2)

print(res)
