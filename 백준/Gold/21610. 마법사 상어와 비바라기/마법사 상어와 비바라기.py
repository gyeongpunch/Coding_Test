import sys
input = sys.stdin.readline

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
commands = [tuple(map(int, input().split())) for _ in range(M)]

clouds = [(N-1, 0), (N-1, 1), (N-2, 0), (N-2, 1)]

dx, dy = [0, -1, -1, -1, 0, 1, 1, 1], [-1, -1, 0, 1, 1, 1, 0, -1]
digonal_dx, digonal_dy = [-1, -1, 1, 1], [-1, 1, 1, -1]

def digonal_cnt(x, y):
    cnt = 0
    for i in range(4):
        nx = x+digonal_dx[i]
        ny = y+digonal_dy[i]
        if 0 <= nx < N and 0 <= ny < N and arr[nx][ny] > 0:
            cnt += 1
    return cnt

for d, s in commands:
    new_clouds = []
    for row, column in clouds:
        # print('row', 'column')
        # print(row, column)
        # print()
        n_row = (row + dx[d-1]*s)%N
        n_column = (column + dy[d-1]*s)%N
        # print('n_row', 'n_column')
        # print(n_row, n_column)
        # print()
        arr[n_row][n_column] += 1
        new_clouds.append((n_row, n_column))

    # print('이동 후 arr')
    # for i in range(N):
    #     print(*arr[i])
    # print()


    visited = set(new_clouds)
    for row, column in new_clouds:
        arr[row][column] += digonal_cnt(row, column)
    
    # print('물 복사 후 arr')
    # for i in range(N):
    #     print(*arr[i])
    # print()
    clouds = []
    for i in range(N):
        for j in range(N):
            if (i, j) not in visited and arr[i][j] >= 2:
                arr[i][j] -= 2
                clouds.append((i, j))
    
    # print('새로운 queue')
    # print(clouds)
    # print()

    # print('새로운 clouds queue에 들어가고 arr')
    # for i in range(N):
    #     print(*arr[i])
    # print()

print(sum(map(sum, arr)))
