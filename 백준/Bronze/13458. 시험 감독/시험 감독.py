import sys
input = sys.stdin.readline

N = int(input())
data = list(map(int, input().split()))
B, C = map(int, input().split())

total_cnt = 0

for a in data:
    a -= B
    total_cnt += 1
    if a > 0:
        total_cnt += a//C + 1 if a%C!=0 else a//C

print(total_cnt)