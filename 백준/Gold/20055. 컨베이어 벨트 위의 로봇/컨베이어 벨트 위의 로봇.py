import sys
input = sys.stdin.readline

N, K = map(int, input().split())
arr = list(map(int, input().split()))
robots = [False] * N
result = 0

def print_state():
    print()
    print(arr)
    print(robots)
    print()

while True:
    result += 1
    arr = [arr[-1]]+arr[:-1]
    robots = [False] + robots[:-1]
    robots[N-1] = False
    # print('after robot walk')
    # print_state()

    for i in range(N-2, -1, -1):
        if not robots[i+1] and robots[i] and arr[i+1] > 0:
            robots[i+1] = True
            arr[i+1] -= 1
            robots[i] = False
            if arr[i+1] == 0:
                K -= 1
    # print('after robot walk')
    # print_state()

    if arr[0] > 0:
        robots[0] = True
        arr[0] -= 1
        if arr[0] == 0:
            K -= 1
    # print('put on the robot')
    # print_state()
    if K <= 0:
        break

print(result)
