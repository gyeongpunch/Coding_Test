while True:
    n = int(input())
    if n == 0:
        break
    n *= (n + 1)
    n //= 2
    print(n)