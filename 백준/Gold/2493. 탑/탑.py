N = int(input())
data = list(map(int, input().split()))

result = [0]*N

stack = []

for i in range(N-1, -1, -1):
    if not stack:
        stack.append((data[i], i))
        continue
    else:
        if stack[-1][0] < data[i]:
            while stack and stack[-1][0] < data[i]:
                num, loc = stack.pop()
                result[loc] = i+1
        stack.append((data[i], i))
print(*result)