import sys
from collections import deque
input = sys.stdin.readline

n,m,p = map(int,input().split())
castle = [deque() for _ in range(p+1)]
power = [0]+list(map(int,input().split()))
graph = [list(input().rstrip()) for _ in range(n)]
cnt = [0]*(p+1)


for i in range(n):
    for j in range(m):
        if graph[i][j] != '.' and graph[i][j] != '#':
            cnt[int(graph[i][j])] += 1
            castle[int(graph[i][j])].append((i,j))



moves = [(0,1),(1,0),(0,-1),(-1,0)]
def bfs():
    is_moved = True
    while is_moved:
        is_moved = False
        for i in range(1,p+1):
            if not castle[i]: # 비어있다면 continue
                continue
            q = castle[i]
            for _ in range(power[i]):
                if not q: # power 연산 중에 비어졌다면 break
                    break
                for _ in range(len(q)):
                    x,y = q.popleft()
                    for movex,movey in moves:
                        nx = x + movex
                        ny = y + movey
                        if 0 <= nx < n and 0 <= ny < m and graph[nx][ny] == '.':
                            graph[nx][ny] = str(i)
                            q.append((nx,ny))
                            cnt[i] += 1
                            is_moved = True

        
bfs()
print(*cnt[1:])