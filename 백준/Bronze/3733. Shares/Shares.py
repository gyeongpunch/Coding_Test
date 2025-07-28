while True:
    try:
        N, S = map(int, input().split())
        print(S // (N+1))
    except ZeroDivisionError:
        print("Error")
    except ValueError:
        print("Error")
    except EOFError:
        break