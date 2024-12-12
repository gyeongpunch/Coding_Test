from collections import deque

N, M, H = map(int, input().split())

arr = [[list(map(int, input().split())) for _ in range(M)] for _ in range(H)]
visited = [[[0]*N for _ in range(M)] for _ in range(H)]
dx, dy, dz = [1, -1, 0, 0, 0, 0], [0, 0, 1, -1, 0, 0], [0, 0, 0, 0, 1, -1]

t_q = deque()
for i in range(H):
    for j in range(M):
        for k in range(N):
            if arr[i][j][k] == 1:
                t_q.append((i, j, k))
                visited[i][j][k] = 1
# print(arr)
# print(visited)

def bfs(q):
    mx = 1
    while q:
        x, y, z = q.popleft()
        for i in range(6):
            nx, ny, nz = x+dx[i], y+dy[i], z+dz[i]
            if 0<=nx<H and 0<=ny<M and 0<=nz<N and visited[nx][ny][nz]==0 and arr[nx][ny][nz]==0:
                q.append((nx, ny, nz))
                visited[nx][ny][nz] = visited[x][y][z] + 1
                arr[nx][ny][nz] = 1
                mx = max(mx, visited[nx][ny][nz])
    
    for i in range(H):
        for j in range(M):
            for k in range(N):
                if arr[i][j][k] == 0:
                    return -1
    
    return mx - 1



print(bfs(t_q))

