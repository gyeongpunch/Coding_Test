from collections import deque

def bfs(start):
    q = deque([start])
    path = []
    while q:
        current = q.popleft()
        if visited[current]:  # 이미 방문한 노드면 종료
            if current in path:  # 현재 노드가 사이클에 포함되었는지 확인
                cycle_start = path.index(current)
                return len(path) - cycle_start  # 사이클의 길이 반환
            return 0  # 사이클이 없으면 0 반환
        visited[current] = 1
        path.append(current)
        q.append(arr[current])
    return 0

T = int(input())
for _ in range(T):
    N = int(input())
    arr = [0] + list(map(int, input().split()))
    visited = [0] * (N + 1)

    total = N
    for i in range(1, N + 1):
        if not visited[i]:
            total -= bfs(i)
    print(total)
