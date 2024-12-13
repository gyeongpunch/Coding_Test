from collections import deque

def bfs(i):
    q = deque([i])
    visited[i] = 1

    lst = [i]
    t_set = set([i])
    while q:
        x = q.popleft()
        if arr[x] in t_set:
            return len(lst) - lst.index(arr[x])
        if visited[arr[x]]==0:
            visited[arr[x]] = 1
            q.append(arr[x])
            lst.append(arr[x])
            t_set.add(arr[x])
    return 0

T = int(input())
for _ in range(T):
    N = int(input())
    arr = [0] + list(map(int, input().split()))
    visited = [0]*(N+1)

    total = N
    for i in range(1, N+1):
        if visited[i] == 0:
            total -= bfs(i)
    print(total)