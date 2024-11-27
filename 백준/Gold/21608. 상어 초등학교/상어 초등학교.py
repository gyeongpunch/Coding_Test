import sys
input = sys.stdin.readline

N = int(input())
data = [list(map(int, input().split())) for _ in range(N*N)]
data_dict = {}
for i in range(N*N):
    a = data[i]
    me = a[0]
    friends = set(a[1:])
    data_dict[me] = friends

arr = [[0]*N for _ in range(N)]
dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

def empty_check(like_state):
    max_value = 0
    empty_state = []
    for x, y in like_state:
        cnt = 0
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<N and arr[nx][ny]==0:
                cnt+=1
        if max_value < cnt:
            max_value = cnt
            empty_state = [(x, y)]
        elif max_value == cnt:
            empty_state.append((x, y))
    return empty_state

def like_check(friends):
    state = []
    max_value = 0
    for x in range(N):
        for y in range(N):
            if arr[x][y] == 0:
                cnt = 0
                for i in range(4):
                    nx, ny = x+dx[i], y+dy[i]
                    if 0<=nx<N and 0<=ny<N and arr[nx][ny] in friends:
                        cnt += 1
                if max_value < cnt:
                    state = [(x, y)]
                    max_value = cnt
                elif max_value == cnt:
                    state.append((x, y))
    return state

for i in range(N*N):
    me = data[i][0]
    friends = set(data[i][1:])
    like_state = like_check(friends)
    # print(me, like_state)
    
    if len(like_state) == 1:
        x, y = like_state[0]
        arr[x][y] = me
    else:
        if len(like_state) == 0:
            like_state = []
            for i in range(N):
                for j in range(N):
                    if arr[i][j] == 0:
                        like_state.append((i, j))
        empty_state = empty_check(like_state)
        if len(empty_state) == 1:
            x, y = empty_state[0]
            arr[x][y] = me
        else:
            empty_state.sort(key=lambda x: (x[0], x[1]))
            x, y = empty_state[0]
            arr[x][y] = me


result = 0
for x in range(N):
    for y in range(N):
        cnt = 0
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<N and 0<=ny<N and arr[nx][ny] in data_dict[arr[x][y]]:
                cnt += 1
        if cnt != 0:
            result += 10**(cnt-1)

print(result)