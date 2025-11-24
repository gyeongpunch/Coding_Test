N, A, B = map(int, input().split())
if A < max(N, B):
    print('Bus')
elif A > max(N, B):
    print('Subway')
else:
    print('Anything')