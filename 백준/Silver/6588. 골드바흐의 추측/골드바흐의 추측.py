import sys
input = sys.stdin.readline

prime_lst = []
prime_set = set()

MAX = 1000000

def is_prime(n):
    for i in range(2, int(n**0.5) + 1):
        if n%i==0:
            return False
    return True

for i in range(2, MAX+1):
    if is_prime(i):
        prime_lst.append(i)
        prime_set.add(i)

# print(prime_lst)
result = []
while True:
    n = int(input())
    if n==0:
        break
    flag = True
    for p in prime_lst:
        if n-p in prime_set:
            result.append(f"{n} = {p} + {n-p}")
            flag = False
            break
    if flag:
        result.append("Goldbach's conjecture is wrong.")

print(*result, sep='\n')