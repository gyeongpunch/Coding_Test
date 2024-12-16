from collections import deque

N, M, P = map(int,input().split())
total_q = [deque() for _ in range(P+1)]
power = [0]+list(map(int,input().split()))
arr = [list(input().strip()) for _ in range(N)]
cnt = [0]*(P+1)
dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

for i in range(N):
    for j in range(M):
        if '1' <= arr[i][j] <= '9':
            p = int(arr[i][j])
            cnt[p] += 1
            total_q[p].append((i, j))

def bfs():
    is_moved = True
    while is_moved:
        is_moved = False
        for i in range(1, P+1):
            if not total_q[i]:
                continue

            q = total_q[i]
            for _ in range(power[i]):
                if not q:
                    break

                for _ in range(len(q)):
                    x, y = q.popleft()
                    for j in range(4):
                        nx, ny = x+dx[j], y+dy[j]

                        if 0<=nx<N and 0<=ny<M and arr[nx][ny] == '.':
                            arr[nx][ny] = str(i)
                            q.append((nx, ny))
                            cnt[i] += 1
                            is_moved = True
        
bfs()
print(*cnt[1:])