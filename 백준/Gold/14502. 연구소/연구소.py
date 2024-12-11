from collections import deque

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
tmp_arr = [arr[i][:] for i in range(N)]
visited = [[0]*M for _ in range(N)]

dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]
result = 0
total = N*M

def is_wall(i, j, k):
    ix, iy = i//M, i%M
    jx, jy = j//M, j%M
    kx, ky = k//M, k%M

    if arr[ix][iy] == 0 and arr[jx][jy] == 0 and arr[kx][ky] == 0:
        arr[ix][iy] = arr[jx][jy] = arr[kx][ky] = 1
        return True
    return False

def bfs(x, y):
    q = deque([(x, y)])
    visited[x][y] = 1

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<M and arr[nx][ny] == 0 and visited[nx][ny] == 0:
                q.append((nx, ny))
                arr[nx][ny] = 2
                visited[nx][ny] = 1


def get_virus():
    for i in range(N):
        for j in range(M):
            if arr[i][j] == 2 and visited[i][j] == 0:
                bfs(i, j)

def get_safe():
    cnt = 0
    for i in range(N):
        for j in range(M):
            if arr[i][j] == 0:
                cnt += 1
    return cnt

for i in range(total-2):
    for j in range(i+1, total-1):
        for k in range(j+1, total):
            if is_wall(i, j, k):
                # print('!!!!!!!!!!!!!')
                get_virus()

                result = max(result, get_safe())

                arr = [tmp_arr[i][:] for i in range(N)]
                visited = [[0]*M for _ in range(N)]

print(result)