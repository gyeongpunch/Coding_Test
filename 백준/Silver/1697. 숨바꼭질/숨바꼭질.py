from collections import deque

N, K = map(int, input().split())
MAX = 100001

def bfs(N, K):
    visited = [-1]*MAX
    visited[N] = 0

    q = deque([N])

    while q:
        # print(visited[:20])
        x = q.popleft()
        nx_lst = [x+1, x-1, 2*x]

        for nx in nx_lst:
            if 0<=nx<MAX and (visited[nx]==-1 or visited[nx] > visited[x] + 1):
                q.append(nx)
                visited[nx] = visited[x] + 1
    return visited[K]
print(bfs(N, K))