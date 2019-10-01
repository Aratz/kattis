t = int(input())
for _ in range(t):
    n = int(input())
    try:
        phone_book = {}
        for j in range(n):
            number = input()
            L = len(number) - 1
            d = phone_book
            for i, c in enumerate(number):
                if i < L:
                    if c in d and d[c] == {}:
                        raise Exception()
                    else:
                        d = d.setdefault(c, {})
                elif c in d:
                    raise Exception()
                else:
                    d[c] = {}
    except Exception:
        print("NO")
    else:
        print("YES")
    finally:
        for _ in range(j + 1, n):
            input()
