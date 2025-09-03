for i in range(3):
    n = input()
    if n.isdigit():
        target = int(n) + 3 - i
        if target%3==0 and target%5==0:
            print('FizzBuzz')
        elif target%3==0:
            print('Fizz')
        elif target%5==0:
            print('Buzz')
        else:
            print(target)
        break