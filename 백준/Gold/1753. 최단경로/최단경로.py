import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

V, E = map(int, input().split())
K = int(input())

adj = [[] for _ in range(V + 1)]
for _ in range(E):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))
dist = [INF] * (V + 1)

def dijkstra(start):
    dist[start] = 0
    pq = []
    heapq.heappush(pq, (0, start))

    while pq:
        d, u = heapq.heappop(pq)
        
        if d > dist[u]: continue

        for v, w in adj[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))

dijkstra(K)

for i in range(1, V + 1):
    if dist[i] == INF:
        print("INF")
    else:
        print(dist[i])