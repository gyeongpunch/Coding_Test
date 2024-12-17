N = int(input())
arr = [list(input()) for _ in range(N)]

def calc():
    mx_cnt_c = 0
    mx_cnt_r = 0
    for i in range(N):
        cnt_c = 1
        now = arr[i][0]
        for j in range(1, N):
            if now==arr[i][j]:
                cnt_c+=1
            else:
                cnt_c = 1
            now = arr[i][j]
            mx_cnt_c = max(mx_cnt_c, cnt_c)

        cnt_r = 1
        now = arr[0][i]
        for j in range(1, N):
            if now==arr[j][i]:
                cnt_r += 1
            else:
                cnt_r = 1
            now = arr[j][i]
            mx_cnt_r = max(mx_cnt_r, cnt_r)

    return max(mx_cnt_r, mx_cnt_c)

result = 0
for i in range(N):
    for j in range(N-1):
        arr[i][j], arr[i][j+1] = arr[i][j+1], arr[i][j]
        result = max(result, calc())
        arr[i][j], arr[i][j+1] = arr[i][j+1], arr[i][j]

        arr[j][i], arr[j+1][i] = arr[j+1][i], arr[j][i]
        result = max(result, calc())
        arr[j][i], arr[j+1][i] = arr[j+1][i], arr[j][i]

print(result)