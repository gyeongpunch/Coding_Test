from collections import deque

N = int(input())
arr = [list(input()) for _ in range(N)]
visited = [[0]*N for _ in range(N)]
dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]
cnt = 0
result = []

def bfs(x, y):
    q = deque([(x, y)])
    visited[x][y] = 1
    now = 1

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<N and arr[nx][ny]=='1' and visited[nx][ny]==0:
                q.append((nx, ny))
                visited[nx][ny] = 1
                now += 1
    result.append(now)

for i in range(N):
    for j in range(N):
        if arr[i][j]=='1' and visited[i][j]==0:
            bfs(i, j)
            cnt += 1
result.sort()
print(cnt)
print(*result, sep='\n')