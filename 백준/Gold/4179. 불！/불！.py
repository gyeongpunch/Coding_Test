from collections import deque

N, M = map(int, input().split())
arr = [list(input()) for _ in range(N)]

dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

fire_visited = [[0] * M for _ in range(N)]
jihun_visited = [[0] * M for _ in range(N)]

fire_queue = deque()
jihun_queue = deque()

for i in range(N):
    for j in range(M):
        if arr[i][j] == 'F':
            fire_queue.append((i, j))
            fire_visited[i][j] = 1
        elif arr[i][j] == 'J':
            jihun_queue.append((i, j))
            jihun_visited[i][j] = 1

def bfs():
    while fire_queue:
        x, y = fire_queue.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0<=nx<N and 0<=ny<M and not fire_visited[nx][ny] and arr[nx][ny] != '#':
                fire_visited[nx][ny] = fire_visited[x][y] + 1
                fire_queue.append((nx, ny))

    while jihun_queue:
        x, y = jihun_queue.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if not (0 <= nx < N and 0 <= ny < M):
                return jihun_visited[x][y]

            if arr[nx][ny] == '.' and not jihun_visited[nx][ny]:
                if fire_visited[nx][ny] == 0 or jihun_visited[x][y] + 1 < fire_visited[nx][ny]:
                    jihun_visited[nx][ny] = jihun_visited[x][y] + 1
                    jihun_queue.append((nx, ny))

    return "IMPOSSIBLE"

print(bfs())
