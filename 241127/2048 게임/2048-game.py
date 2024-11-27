NUM_MOVES = 5
NONE = -1

n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]
next_grid = [[0 for _ in range(n)] for _ in range(n)]
temp = [[0 for _ in range(n)] for _ in range(n)]

move_dirs = [0 for _ in range(NUM_MOVES)]

ans = 0

def get_max_block_num():
    return max([grid[i][j]
        for i in range(n)
        for j in range(n)
    ])

def rotate():
    for i in range(n):
        for j in range(n):
            next_grid[i][j] = 0
    
    for i in range(n):
        for j in range(n):
            next_grid[i][j] = grid[n - j - 1][i]
    
    for i in range(n):
        for j in range(n):
            grid[i][j] = next_grid[i][j]

def drop():
    for i in range(n):
        for j in range(n):
            next_grid[i][j] = 0
    
    for j in range(n):
        keep_num, next_row = NONE, n - 1
        
        for i in range(n - 1, -1, -1):
            if not grid[i][j]:
                continue
            
            if keep_num == NONE:
                keep_num = grid[i][j];
            
            elif keep_num == grid[i][j]:
                next_grid[next_row][j] = keep_num * 2
                
                keep_num = NONE
                next_row -= 1
            
            else:
                next_grid[next_row][j] = keep_num
                
                keep_num = grid[i][j]
                next_row -= 1
        
        if keep_num != NONE:
            next_grid[next_row][j] = keep_num
            next_row -= 1
    
    for i in range(n):
        for j in range(n):
            grid[i][j] = next_grid[i][j]

def tilt(move_dir):
    for _ in range(move_dir):
        rotate()

    drop()
    
    for _ in range(4 - move_dir):
        rotate()


def simulate():
    global ans
    
    for i in range(n):
        for j in range(n):
            temp[i][j] = grid[i][j]
    
    for move_dir in move_dirs:
        tilt(move_dir)
    
    ans = max(ans, get_max_block_num())
    
    for i in range(n):
        for j in range(n):
            grid[i][j] = temp[i][j]


def search_max_num(cnt):
    if cnt == NUM_MOVES:
        simulate()
        return

    for i in range(4):
        move_dirs[cnt] = i
        search_max_num(cnt + 1)
        # print(move_dirs)

search_max_num(0)
print(ans)