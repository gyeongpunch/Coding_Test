import sys
import heapq

input = sys.stdin.readline
N = int(input())
data = [tuple(map(int, input().split())) for _ in range(N)]

data.sort(key=lambda x : x[0])

heap = []

heapq.heappush(heap, data[0][1])

for i in range(1, N):
    if heap[0] <= data[i][0]:
        heapq.heappop(heap)
    heapq.heappush(heap, data[i][1])
print(len(heap))