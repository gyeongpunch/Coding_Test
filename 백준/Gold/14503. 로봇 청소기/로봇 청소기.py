from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
r, c, d = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

dx, dy = [-1, 0, 1, 0], [0, 1, 0, -1]
result = 0
def solution(r, c, d):
    global result
    q = deque([(r, c, d)])

    while q:
        r, c, d = q.popleft()
        if arr[r][c] == 0:
            result += 1
            arr[r][c] = 2
        
        is_check = False
        nd = d
        for _ in range(4):
            nd = (nd+3)%4
            nr, nc = r+dx[nd], c+dy[nd]
            if arr[nr][nc] == 0:
                q.append((nr, nc, nd))
                is_check = True
                break

        if not is_check:
            bd = (d+2)%4
            br, bc = r+dx[bd], c+dy[bd]
            if arr[br][bc] == 1:
                break
            else:
                q.append((br, bc, d))

solution(r, c, d)
print(result)