from collections import deque

N, M = map(int, input().split())
arr = [list(input()) for _ in range(N)]

dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

j_q = deque()
f_q = deque()
j_v = [[0]*M for _ in range(N)]
f_v = [[0]*M for _ in range(N)]

for i in range(N):
    for j in range(M):
        if arr[i][j] == 'J':
            j_q.append((i, j))
            j_v[i][j] = 1

        elif arr[i][j] == 'F':
            f_q.append((i, j))
            f_v[i][j] = 1

def bfs():
    while f_q:
        x, y = f_q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<M and f_v[nx][ny]==0 and arr[nx][ny]!='#':
                f_q.append((nx, ny))
                f_v[nx][ny] = f_v[x][y] + 1

    while j_q:
        x, y = j_q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if not (0<=nx<N and 0<=ny<M):
                return j_v[x][y]

            elif j_v[nx][ny]==0 and arr[nx][ny]!='#' and (j_v[x][y]+1 < f_v[nx][ny] or f_v[nx][ny] == 0):
                j_q.append((nx, ny))
                j_v[nx][ny] = j_v[x][y] + 1

    return 'IMPOSSIBLE'


print(bfs())