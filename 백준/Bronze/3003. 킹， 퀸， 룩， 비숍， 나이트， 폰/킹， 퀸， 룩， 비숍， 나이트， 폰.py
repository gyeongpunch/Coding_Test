arr = list(map(int, input().split()))

arr[0] = 1 - arr[0]
arr[1] = 1 - arr[1]
arr[2] = 2 - arr[2]
arr[3] = 2 - arr[3]
arr[4] = 2 - arr[4]
arr[5] = 8 - arr[5]
print(*arr)