from itertools import combinations
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

chicken = []
house = []
for i in range(N):
    for j in range(N):
        if arr[i][j] == 2:
            chicken.append((i, j))
        elif arr[i][j] == 1:
            house.append((i, j))

chicken_com = combinations(chicken, M)

def calc(house, chicken_loc):
    total_dist = 0
    for hx, hy in house:
        min_dist = float('inf')
        for cx, cy in chicken_loc:
            min_dist = min(min_dist, abs(hx-cx)+abs(hy-cy))
        total_dist += min_dist
    return total_dist

result = float('inf')
for chicken_loc in chicken_com:
    result = min(result, calc(house, chicken_loc))

print(result)