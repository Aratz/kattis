board = []
for _ in range(4):
    board += [[int(i) for i in input().split()]]
d = int(input())
if d==0:
    for i in range(4):
        for j in range(4):
            if board[i][j] == 0:
                continue
            else:
                if j != 0:
                    k = j-1
                    while board[i][k] == 0 and k>0:
                        k-=1
                    if board[i][k] == 0:
                        board[i][k] = board[i][j]
                        board[i][j] = 0
                    elif board[i][k] == board[i][j]:
                        board[i][k] = -board[i][j]*2
                        board[i][j] = 0
                    elif k+1 != j:
                        board[i][k+1] = board[i][j]
                        board[i][j] = 0
elif d==1:
    for j in range(4):
        for i in range(4):
            if board[i][j] == 0:
                continue
            else:
                if i != 0:
                    k = i-1
                    while board[k][j] == 0 and k>0:
                        k-=1
                    if board[k][j] == 0:
                        board[k][j] = board[i][j]
                        board[i][j] = 0
                    elif board[k][j] == board[i][j]:
                        board[k][j] = -board[i][j]*2
                        board[i][j] = 0
                    elif k+1 != i:
                        board[k+1][j] = board[i][j]
                        board[i][j] = 0
elif d==2:
    for i in range(4):
        for j in range(4):
            j = 3-j
            if board[i][j] == 0:
                continue
            else:
                if j != 3:
                    k = j+1
                    while board[i][k] == 0 and k<3:
                        k+=1
                    if board[i][k] == 0:
                        board[i][k] = board[i][j]
                        board[i][j] = 0
                    elif board[i][k] == board[i][j]:
                        board[i][k] = -board[i][j]*2
                        board[i][j] = 0
                    elif k-1 != j:
                        board[i][k-1] = board[i][j]
                        board[i][j] = 0
elif d==3:
    for j in range(4):
        for i in range(4):
            i = 3-i
            if board[i][j] == 0:
                continue
            else:
                if i != 3:
                    k = i+1
                    while board[k][j] == 0 and k<3:
                        k+=1
                    if board[k][j] == 0:
                        board[k][j] = board[i][j]
                        board[i][j] = 0
                    elif board[k][j] == board[i][j]:
                        board[k][j] = -board[i][j]*2
                        board[i][j] = 0
                    elif k-1 != i:
                        board[k-1][j] = board[i][j]
                        board[i][j] = 0
for line in board:
    print(*[abs(i) for i in line])

