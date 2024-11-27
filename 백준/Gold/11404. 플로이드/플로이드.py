import sys
input = sys.stdin.readline

n = int(input())
m = int(input())

D = [[sys.maxsize for _ in range(n + 1)] for _ in range(n + 1)] 

for i in range(n + 1):
    D[i][i] = 0

for i in range(m):
    start, end, cost = map(int, input().split())
    if D[start][end] > cost:
        D[start][end] = cost

for k in range(1, n + 1):
    for j in range(1, n + 1):
        for i in range(1, n + 1):
            if D[i][j] > D[i][k] + D[k][j]:
                D[i][j] = D[i][k] + D[k][j]

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if D[i][j] == sys.maxsize:
            print(0, end = ' ')
        else:
            print(D[i][j], end = ' ')
    print()