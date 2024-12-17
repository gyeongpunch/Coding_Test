import sys
# sys.stdin = open("input.txt", "r")

input = sys.stdin.readline

T = int(input())

MAX = 1000000

f = [0] * (MAX+1)

for i in range(1, MAX+1):
    for j in range(i, MAX+1, i):
        f[j] += i

g = [0] * (MAX+1)

for i in range(1, MAX+1):
    g[i] = g[i - 1] + f[i]

answer = []
for _ in range(T):
    n = int(input())
    answer.append(g[n])

print(*answer, sep='\n')