from collections import deque

dx, dy, dz = [1, -1, 0, 0, 0, 0], [0, 0, 1, -1, 0, 0], [0, 0, 0, 0, 1, -1]

def bfs(q, end):
    while q:
        x, y, z, t = q.popleft()
        # print(x, y, z)
        # print(end)
        # print()
        if (x, y, z) == end:
            return f"Escaped in {t-1} minute(s)."
        for i in range(6):
            nx, ny, nz = x+dx[i], y+dy[i], z+dz[i]
            if 0<=nx<L and 0<=ny<R and 0<=nz<C and visited[nx][ny][nz]==0 and arr[nx][ny][nz]!='#':
                q.append((nx, ny, nz, t+1))
                visited[nx][ny][nz] = 1
    
    return 'Trapped!'

while True:
    L, R, C = map(int, input().split())
    if L==0 and R==0 and C==0:
        break

    arr = []
    for _ in range(L):
        layer = [list(input()) for _ in range(R)]
        arr.append(layer)
        input()
    visited = [[[0]*C for _ in range(R)] for _ in range(L)]

    # print(arr)
    q = deque()
    for i in range(L):
        for j in range(R):
            for k in range(C):
                if arr[i][j][k] == 'S':
                    q.append((i, j, k, 1))
                elif arr[i][j][k] == 'E':
                    end = (i, j, k)
    
    print(bfs(q, end))