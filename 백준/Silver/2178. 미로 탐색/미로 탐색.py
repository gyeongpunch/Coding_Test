from collections import deque

N, M = map(int, input().split())
arr = [list(input()) for _ in range(N)]
visited = [[0]*M for _ in range(N)]

dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

def bfs():
    q = deque([(0, 0, 1)])
    visited[0][0] = 1
    
    while q:
        x, y, now = q.popleft()
        if x == N-1 and y == M-1:
            return now

        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<M and visited[nx][ny] == 0 and arr[nx][ny] == '1':
                q.append((nx, ny, now+1))
                visited[nx][ny] = 1

print(bfs())