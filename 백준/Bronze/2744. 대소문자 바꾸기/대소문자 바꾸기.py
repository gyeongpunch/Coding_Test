s = input()
ret = ''
for c in s:
    if c.isupper():
        ret += c.lower()
    else:
        ret += c.upper()
print(ret)