def countStar(l):
    return sum([1 if c=='*' else 0 for c in l])

board = [input() for i in range(8)]

for i in range(8):
    if countStar(board[i])!=1:
        print('invalid')
        break
    if countStar([board[j][i] for j in range(8)])!=1:
        print('invalid')
        break
else:
    sDiagD = [(0,i) for i in range(8)] + [(i,0) for i in range(1,8)]
    diag = [[(xi+i,yi+i) for i in range(8-max(xi,yi))] for xi,yi in sDiagD]
    sDiagI = [(7,i) for i in range(8)] + [(i,0) for i in range(7)]
    diag += [[(xi-i,yi+i) for i in range(min(xi+1,8-yi))] for xi,yi in sDiagI]
    for l in diag:
        if countStar([board[i][j] for i,j in l]) > 1:
            print('invalid')
            break
    else:
        print('valid')
        

