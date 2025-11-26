import sys
input = sys.stdin.readline

n = int(input())
data = list(map(int, input().split()))

stack = []
result = [0] * n

for i in range(n):
    while stack and data[stack[-1]] < data[i]:
        result[stack.pop()] = data[i]
    stack.append(i)
while stack:
    result[stack.pop()] = -1

for i in result:
    print(i, end = ' ')