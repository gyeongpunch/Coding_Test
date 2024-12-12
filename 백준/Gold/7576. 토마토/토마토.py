from collections import deque

M, N = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
visited = [[0]*M for _ in range(N)]
dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]
# print(arr)

def bfs(lst):
    q = deque(lst)
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<M and visited[nx][ny] == 0 and arr[nx][ny] != -1:
                q.append((nx, ny))
                visited[nx][ny] = 1
                arr[nx][ny] = arr[x][y] + 1
    mx = 0
    for i in range(N):
        for j in range(M):
            if arr[i][j] == 0:
                return -1
            mx = max(mx, arr[i][j]-1)
    return mx


even = []
for i in range(N):
    for j in range(M):
        if arr[i][j] == 1:
            even.append((i, j))
            visited[i][j] = 1

print(bfs(even))