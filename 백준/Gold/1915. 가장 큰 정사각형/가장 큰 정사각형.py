N, M = map(int, input().split())
arr = [list(input()) for _ in range(N)]

dp = [[0]*(M+1) for _ in range(N+1)]

mx = 0
for i in range(1, N+1):
    for j in range(1, M+1):
        if arr[i-1][j-1] == '1':
            dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
            mx = max(mx, dp[i][j])
# for i in range(1, N+1):
#     print(dp[i])
print(mx*mx)