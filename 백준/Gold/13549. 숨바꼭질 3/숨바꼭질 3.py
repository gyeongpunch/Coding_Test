from collections import deque

N, K = map(int, input().split())
visited = [-1]*100001

def bfs(N, K):
    q = deque([N])
    visited[N] = 0

    while q:
        X = q.popleft()
        
        next = [X * 2, X + 1, X - 1]

        for np in next:
            if 0 <= np <= 100000:
                if np == X * 2:
                    if visited[np]==-1 or (visited[np]!=-1 and visited[np]>visited[X]):
                        q.append(np)
                        visited[np] = visited[X]
                else:
                    if visited[np]==-1 or (visited[np]!=-1 and visited[np]>visited[X]+1):
                        q.append(np)
                        visited[np] = visited[X] + 1
    # print(visited[:50])
    return visited[K]

print(bfs(N, K))