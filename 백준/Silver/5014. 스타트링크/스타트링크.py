from collections import deque

F, S, G, U, D = map(int, input().split())
visited = [-1] * (F+1)

def bfs():
    q = deque([S])
    visited[S] = 0

    while q:
        x = q.popleft()
        n_pos = [x+U, x-D]
        for nx in n_pos:
            if 0<nx<=F and (visited[nx]==-1 or visited[nx] > visited[x] + 1):
                q.append(nx)
                visited[nx] = visited[x] + 1
    return visited[G] if visited[G]!=-1 else 'use the stairs'

print(bfs())