from collections import deque

T = int(input())
dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

def bfs(s_q, f_q, s_v, f_v):
    while f_q:
        x, y = f_q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<M and f_v[nx][ny]==0 and arr[nx][ny]!='#':
                f_q.append((nx, ny))
                f_v[nx][ny] = f_v[x][y] + 1

    while s_q:
        x, y = s_q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if not (0<=nx<N and 0<=ny<M):
                return s_v[x][y]

            elif s_v[nx][ny]==0 and arr[nx][ny]=='.' and (s_v[x][y]+1 < f_v[nx][ny] or f_v[nx][ny]==0):
                s_q.append((nx, ny))
                s_v[nx][ny] = s_v[x][y] + 1

    return 'IMPOSSIBLE'


for t in range(T):
    M, N = map(int, input().split())
    arr = [list(input()) for _ in range(N)]

    s_q = deque()
    f_q = deque()
    s_v = [[0]*M for _ in range(N)]
    f_v = [[0]*M for _ in range(N)]
    for i in range(N):
        for j in range(M):
            if arr[i][j] == '@':
                s_q.append((i, j))
                s_v[i][j] = 1
            elif arr[i][j] == '*':
                f_q.append((i, j))
                f_v[i][j] = 1
    
    print(bfs(s_q, f_q, s_v, f_v))