import sys
input = sys.stdin.readline

N = int(input())
M = int(input())

parent = [i for i in range(N + 1)]
city = [[0 for j in range(N + 1)] for i in range(N + 1)]

def find(a):
    if parent[a] == a:
        return a
    else:
        parent[a] = find(parent[a])
        return parent[a]

def union(a, b):
    a = find(a)
    b = find(b)
    if a != b:
        parent[b] = a
    

for i in range(1, N + 1):
    city[i] = list(map(int, input().split()))
    city[i].insert(0, 0)

route = list(map(int, input().split()))
route.insert(0, 0)

for i in range(1, N + 1):
    for j in range(1, N + 1):
        if city[i][j] == 1:
            union(i, j)

index = find(route[1])
isConnect = True

for i in range(2, M + 1):
    if index != find(route[i]):
        isConnect = False
        break
if isConnect:
    print('YES')
else:
    print('NO')