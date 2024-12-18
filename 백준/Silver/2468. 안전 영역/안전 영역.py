from collections import deque

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

def bfs(x, y, h):
    q = deque([(x, y)])
    visited[x][y] = h

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<N and arr[nx][ny]>h and visited[nx][ny]!=h:
                q.append((nx, ny))
                visited[nx][ny] = h

mx = 0
visited = [[-1]*N for _ in range(N)]
for h in range(0, 101):
    cnt = 0
    for i in range(N):
        for j in range(N):
            if arr[i][j]>h and visited[i][j]!=h:
                bfs(i, j, h)
                cnt += 1
    mx = max(mx, cnt)
    # print(mx)

print(mx)