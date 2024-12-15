from collections import deque

K = int(input())
M, N = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
visited = [[[-1]*(K+1) for _ in range(M)] for _ in range(N)]
dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]
hdx, hdy = [-2, -1, 1, 2, 2, 1, -1, -2], [1, 2, 2, 1, -1, -2, -2, -1]

def bfs():
    q = deque([(0, 0, 0)])
    visited[0][0][0] = 0

    while q:
        x, y, use = q.popleft()

        if use < K:
            for i in range(8):
                nx, ny = x+hdx[i], y+hdy[i]
                if 0<=nx<N and 0<=ny<M and arr[nx][ny]!=1 and visited[nx][ny][use+1]==-1:
                    q.append((nx, ny, use+1))
                    visited[nx][ny][use+1] = visited[x][y][use] + 1
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<M and arr[nx][ny]!=1 and visited[nx][ny][use]==-1:
                q.append((nx, ny, use))
                visited[nx][ny][use] = visited[x][y][use] + 1
    result = [visited[N-1][M-1][i] for i in range(K+1) if visited[N-1][M-1][i] != -1]
    return min(result) if result else -1
print(bfs())