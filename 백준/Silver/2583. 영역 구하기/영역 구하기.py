from collections import deque

N, M, K = map(int, input().split())
arr = [[0]*M for _ in range(N)]
visited = [[0]*M for _ in range(N)]
dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

for _ in range(K):
    x1, y1, x2, y2 = map(int, input().split())
    for x in range(x1, x2):
        for y in range(y1, y2):
            arr[y][x] += 1
    
# print()
# for i in range(N):
#     print(arr[i])
# print()

def bfs(x, y, size):
    q = deque([(x, y)])
    visited[x][y]=1
    size += 1

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<M and arr[nx][ny]==0 and visited[nx][ny]==0:
                q.append((nx, ny))
                visited[nx][ny] = 1
                size += 1
    result.append(size)

cnt = 0
result = []
for i in range(N):
    for j in range(M):
        if arr[i][j]==0 and visited[i][j]==0:
            bfs(i, j, 0)
            cnt += 1
result.sort()
print(cnt)
print(*result)