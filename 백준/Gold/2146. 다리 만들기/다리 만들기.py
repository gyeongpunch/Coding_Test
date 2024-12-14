from collections import deque

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
visited = [[0]*N for _ in range(N)]
dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

def bfs(x, y, now):
    q = deque([(x, y)])
    visited[x][y] = 1
    arr[x][y] = now

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<N and arr[nx][ny]==1 and visited[nx][ny]==0:
                q.append((nx, ny))
                visited[nx][ny] = 1
                arr[nx][ny] = now


now = 1
beach = []
for x in range(N):
    for y in range(N):
        if arr[x][y] == 1:
            is_avail = False
            for i in range(4):
                nx, ny = x+dx[i], y+dy[i]
                if 0<=nx<N and 0<=ny<N and arr[nx][ny]==0:
                    is_avail = True
                    break
            if is_avail:
                beach.append((x, y))

            if visited[x][y] == 0:
                bfs(x, y, now)
                now += 1

# print(arr)
# print(beach)

def get_min_d(x, y, my_data):
    visited = [[0]*N for _ in range(N)]
    q = deque([(x, y, 0)])
    visited[x][y] = 1

    while q:
        x, y, d = q.popleft()

        if arr[x][y]!=0 and arr[x][y]!=my_data:
            return d - 1

        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<N and arr[nx][ny] != my_data and visited[nx][ny]==0:
                q.append((nx, ny, d+1))
                visited[nx][ny] = 1


result = float('inf')
for x, y in beach:
    result = min(result, get_min_d(x, y, arr[x][y]))

print(result)