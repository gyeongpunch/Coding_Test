a = list(input())

now = 0
loc = -1
for i in range(len(a)-1):
    if a[i].isdigit():
        if i % 2 == 0:
            now += int(a[i])
        else:
            now += int(a[i]) * 3
    else:
        loc = i

result = 0
if loc == -1:
    result = (10 - now) % 10
else:
    for i in range(10):
        if loc % 2 == 0:
            if (now + i + int(a[-1])) % 10 == 0:
                result = i
                break
        else:
            if (now + i*3 + int(a[-1])) % 10 == 0:
                result = i
                break

print(result)