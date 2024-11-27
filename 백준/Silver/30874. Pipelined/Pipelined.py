import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
arr.sort()
result = arr[-1] + len(arr)-1

print(result)
