N, K = map(int, input().split())

def combination(N, K):
    if K == 0 or K == N:
        return 1
    return combination(N - 1, K - 1) + combination(N - 1, K)

result = combination(N, K)

print(result)