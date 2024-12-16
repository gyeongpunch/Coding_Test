N = int(input())
K = int(input())
MOD = 1000000003

if K > N // 2:
    print(0)
    exit()

dp = [[0]*(K+1) for _ in range(N+1)]

for n in range(1, N+1):
    dp[n][0] = 1
    if n>=2:
        dp[n][1] = n

for n in range(3, N+1):
    for k in range(2, K+1):
        dp[n][k] = (dp[n-2][k-1] + dp[n-1][k]) % MOD

print(dp[N][K])