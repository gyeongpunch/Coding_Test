import sys
input = sys.stdin.readline

N, M = map(int, input().split())
A = [[] for _ in range(N + 1)]
edge = []
D = [sys.maxsize] * (N + 1)

for i in range(M):
    start, end, time = map(int, input().split())
    edge.append((start, end, time))

D[1] = 0

for _ in range(N - 1):
    for start, end, time in edge:
        if D[start] != sys.maxsize and D[end] > D[start] + time:
            D[end] = D[start] + time

m_Cycle = False

for start, end, time in edge:
    if D[start] != sys.maxsize and D[end] > D[start] + time:
        m_Cycle = True

if not m_Cycle:
    for i in range(2, N + 1):
        if D[i] != sys.maxsize:
            print(D[i])
        else:
            print(-1)
else:
    print(-1)