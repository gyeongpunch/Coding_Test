from collections import deque

T = int(input())
dx, dy = [-2, -1, 1, 2, 2, 1, -1, -2], [1, 2, 2, 1, -1, -2, -2, -1]

def bfs(s_x, s_y, t_x, t_y):
    q = deque([(s_x, s_y)])
    visited[s_x][s_y] = 0

    while q:
        x, y = q.popleft()
        if x==t_x and y==t_y:
            return visited[x][y]

        for i in range(8):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<I and 0<=ny<I and visited[nx][ny]==-1:
                q.append((nx, ny))
                visited[nx][ny] = visited[x][y] + 1


for _ in range(T):
    I = int(input())
    visited = [[-1]*I for _ in range(I)]
    start_x, start_y = map(int, input().split())
    target_x, target_y = map(int, input().split())

    print(bfs(start_x, start_y, target_x, target_y))