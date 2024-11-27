import sys
input = sys.stdin.readline

data = [list(input().strip()) for _ in range(4)]
N = int(input())
commands = [list(map(int, input().split())) for _ in range(N)]

def rotate(num, d):
    if d == 1:
        data[num] = [data[num][-1]] + data[num][:-1]
    elif d == -1:
        data[num] = data[num][1:] + [data[num][0]]

def simulation(num, d):
    rotation = [0] * 4 
    rotation[num] = d

    for i in range(num - 1, -1, -1):
        if data[i][2] != data[i + 1][6]:
            rotation[i] = -rotation[i + 1]
        else:
            break

    for i in range(num + 1, 4):
        if data[i - 1][2] != data[i][6]:
            rotation[i] = -rotation[i - 1]
        else:
            break

    for i in range(4):
        if rotation[i] != 0:
            rotate(i, rotation[i])

for num, d in commands:
    simulation(num - 1, d)

result = 0
for i in range(4):
    if data[i][0] == '1':
        result += 2**i

print(result)
