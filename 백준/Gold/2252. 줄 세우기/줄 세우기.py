import sys
input = sys.stdin.readline
from collections import deque

N, M = map(int, input().split())
A = [[] for _ in range(N + 1)]
D = [0] * ( N + 1)

for i in range(M):
    start, end = map(int, input().split())
    A[start].append(end)
    D[end] += 1

queue = deque()

for i in range(1, N + 1):
    if D[i] == 0:
        queue.append(i)
# print(A)
# print(D)
# print(queue)
while queue:
    now = queue.popleft()
    print(now, end = ' ')
    for next in A[now]:
        D[next] -= 1
        if D[next] == 0:
            queue.append(next)