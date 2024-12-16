T = int(input())
for _ in range(T):
    N = int(input())
    data = list(map(int, input().split()))
    M = int(input())

    dp = [0] * (M+1)
    dp[0] = 1

    for coin in data:
        for x in range(coin, M+1):
            dp[x] += dp[x-coin]
        # print(dp)
    
    print(dp[M])