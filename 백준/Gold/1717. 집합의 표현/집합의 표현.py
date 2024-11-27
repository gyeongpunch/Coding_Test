import sys
input = sys.stdin.readline

n, m = map(int, input().split()) # n : n + 1개의 집합, m : 연산 개수

A = [i for i in range(n + 1)]

def find(a):
    if A[a] == a:
        return a
    else:
        A[a] = find(A[a])
        return A[a]

def union(a, b):
    a = find(a)
    b = find(b)

    if a != b:
        A[b] = a

def checkSame(a, b):
    a = find(a)
    b = find(b)

    if a == b:
        return True
    return False

for _ in range(m):
    operator, a, b = map(int, input().split())
    if operator == 0:
        union(a, b)
    else:
        if checkSame(a, b):
            print('YES')
        else:
            print('NO')