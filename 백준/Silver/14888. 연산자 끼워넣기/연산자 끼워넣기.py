import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
operand = list(map(int, input().split()))

max_result = -float('inf')
min_result = float('inf')

stack = []

def calc(numbers, operands):
    num = numbers[0]
    for i in range(N-1):
        op = operands[i]
        if op == 0:
            num += numbers[i+1]
        elif op == 1:
            num -= numbers[i+1]
        elif op == 2:
            num *= numbers[i+1]
        elif op == 3:
            if num < 0 and numbers[i+1] > 0:
                num = -(-num//numbers[i+1])
            else:
                num //=numbers[i+1]
    return num

def dfs(cnt):
    global max_result, min_result

    if cnt == N-1:
        sub_result = calc(arr, stack)
        max_result = max(max_result, sub_result)
        min_result = min(min_result, sub_result)
        return

    for i in range(4):
        if operand[i] > 0:
            operand[i] -= 1
            stack.append(i)
            dfs(cnt + 1)
            operand[i] += 1
            stack.pop()

dfs(0)

print(max_result)
print(min_result)