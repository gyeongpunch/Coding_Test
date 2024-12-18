from collections import deque

T = int(input())
dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

def bfs(x, y):
    q = deque([(x, y)])
    visited[x][y] = 1

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<M and arr[nx][ny]==1 and visited[nx][ny]==0:
                q.append((nx, ny))
                visited[nx][ny] = 1

for _ in range(T):
    M, N, K = map(int, input().split())
    arr = [[0]*M for _ in range(N)]
    visited = [[0]*M for _ in range(N)]
    for _ in range(K):
        y, x = map(int, input().split())
        arr[x][y] = 1
    
    cnt = 0
    for x in range(N):
        for y in range(M):
            if arr[x][y]==1 and visited[x][y]==0:
                bfs(x, y)
                cnt += 1
    # print()
    # for i in range(N):
    #     print(visited[i])
    # print()
    
    print(cnt)