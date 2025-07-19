T = int(input())
for _ in range(T):
    a, b = map(int, input().split())
    a = a % 10
    if a == 0:
        print(10)
        continue

    pattern = []
    check = set()
    current = a
    while current not in check:
        check.add(current)
        pattern.append(current)
        current = (current * a) % 10

    index = (b - 1) % len(pattern)
    print(pattern[index])
