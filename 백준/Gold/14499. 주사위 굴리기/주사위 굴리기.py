N, M, x, y, K = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
commands = list(map(int, input().split()))

dice = [[0]*3 for _ in range(4)]
dice[3][1] = arr[x][y]
dx, dy = [0, 0, -1, 1], [1, -1, 0, 0]

def rotate(direction):
    global dice

    tmp = dice[3][1]
    if direction == 0:
        dice[3][1] = dice[1][2]
        dice[1][2] = dice[1][1]
        dice[1][1] = dice[1][0]
        dice[1][0] = tmp
    
    elif direction == 1:
        dice[3][1] = dice[1][0]
        dice[1][0] = dice[1][1]
        dice[1][1] = dice[1][2]
        dice[1][2] = tmp
    
    elif direction == 2:
        dice[3][1] = dice[0][1]
        dice[0][1] = dice[1][1]
        dice[1][1] = dice[2][1]
        dice[2][1] = tmp
    
    elif direction == 3:
        dice[3][1] = dice[2][1]
        dice[2][1] = dice[1][1]
        dice[1][1] = dice[0][1]
        dice[0][1] = tmp

def copy(nx, ny):
    if arr[nx][ny] == 0:
        arr[nx][ny] = dice[3][1]
    else:
        dice[3][1] = arr[nx][ny]
        arr[nx][ny] = 0
        

def simulation():
    global x, y

    for index in range(K):
        direct = commands[index]-1
        nx, ny = x+dx[direct], y+dy[direct]

        if 0<=nx<N and 0<=ny<M:
            rotate(direct)

            copy(nx, ny)

            print(dice[1][1])

            x, y = nx, ny

simulation()
