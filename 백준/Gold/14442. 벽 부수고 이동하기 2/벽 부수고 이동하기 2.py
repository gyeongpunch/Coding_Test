from collections import deque

N, M, K = map(int, input().split())
arr = [list(map(int, input().strip())) for _ in range(N)]
visited = [[[0]*(K+1) for _ in range(M)] for _ in range(N)]
dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

def print_v():
    print()
    for i in range(N):
        print(visited[i])
    print()

def bfs():
    q = deque([(0, 0, 0)])
    visited[0][0][0] = 1

    while q:
        x, y, broke_cnt = q.popleft()
        
        if x==N-1 and y==M-1:
            return visited[x][y][broke_cnt]
        
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<M:
                if arr[nx][ny] == 0:
                    if visited[nx][ny][broke_cnt]==0:
                        q.append((nx, ny, broke_cnt))
                        visited[nx][ny][broke_cnt] = visited[x][y][broke_cnt] + 1
                else:
                    if broke_cnt < K and visited[nx][ny][broke_cnt+1]==0:
                        q.append((nx, ny, broke_cnt + 1))
                        visited[nx][ny][broke_cnt+1] = visited[x][y][broke_cnt] + 1
    return -1

print(bfs())