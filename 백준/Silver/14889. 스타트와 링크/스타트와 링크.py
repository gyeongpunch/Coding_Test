import sys
input = sys.stdin.readline

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
visited = [False for _ in range(N)]
result = float('inf')

def dfs(cnt, idx):
    global result
    if cnt == N//2:
        A = 0
        B = 0
        for i in range(N):
            for j in range(N):
                if visited[i] and visited[j]:
                    A += arr[i][j]
                elif not visited[i] and not visited[j]:
                    B += arr[i][j]
        result = min(result, abs(A-B))
        # print(visited)
        return
    for i in range(idx, N):
        visited[i] = True
        dfs(cnt+1, i+1)
        visited[i] = False

dfs(0, 0)

print(result)