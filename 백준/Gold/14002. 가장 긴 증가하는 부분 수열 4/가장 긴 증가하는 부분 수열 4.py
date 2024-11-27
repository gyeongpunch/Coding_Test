from bisect import bisect_left
import sys
input = sys.stdin.readline

N = int(input())
data = list(map(int, input().split()))

lis = []
pos = [0] * N

for i in range(N):
    idx = bisect_left(lis, data[i])
    
    if idx == len(lis):
        lis.append(data[i])
    else:
        lis[idx] = data[i]
    pos[i] = idx

length = len(lis)

result = []
current_idx = length - 1
for i in range(N - 1, -1, -1):
    if pos[i] == current_idx:
        result.append(data[i])
        current_idx -= 1

print(length)
print(*result[::-1])
