import sys
input = sys.stdin.readline

n = int(input())
data = list(map(int, input().split()))
answer = 0
data.sort()

for k in range(n):
    i = 0
    j = n - 1
    while i < j:
        if data[i] + data[j] == data[k]:
            if i != k and j != k:
                answer += 1
                break
            elif i == k:
                i += 1
            elif j == k:
                j -= 1
        elif data[i] + data[j] > data[k]:
            j -= 1
        else:
            i += 1

print(answer)
