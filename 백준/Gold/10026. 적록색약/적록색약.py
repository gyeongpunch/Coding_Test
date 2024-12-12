from collections import deque

N = int(input())
arr = [list(input()) for _ in range(N)]

normal = [[0]*N for _ in range(N)]
sack = [[0]*N for _ in range(N)]
n_cnt = 0
s_cnt = 0

dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

def bfs(x, y, visited, op):
    q = deque([(x, y)])
    visited[x][y] = 1

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<N and visited[nx][ny]==0:
                if op == 'normal' and arr[x][y] == arr[nx][ny]:
                    q.append((nx, ny))
                    visited[nx][ny] = 1
                elif op == 'sack' and (arr[x][y] != 'B' and arr[nx][ny] != 'B') or (arr[x][y] == 'B' and arr[nx][ny] == 'B'):
                    q.append((nx, ny))
                    visited[nx][ny] = 1

for i in range(N):
    for j in range(N):
        if normal[i][j] == 0:
            bfs(i, j, normal, 'normal')
            n_cnt += 1
        if sack[i][j] == 0:
            bfs(i, j, sack, 'sack')
            s_cnt += 1

print(n_cnt, s_cnt)
