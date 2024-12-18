def check_max(candy):
    max_candy = 0

    for i in range(len(candy)):
        count = 1
        for j in range(1, len(candy[i])):
            if candy[i][j] == candy[i][j - 1]:
                count += 1
            else:
                max_candy = max(max_candy, count)
                count = 1
        max_candy = max(max_candy, count)

    for j in range(len(candy)):
        count = 1
        for i in range(1, len(candy)):
            if candy[i][j] == candy[i - 1][j]:
                count += 1
            else:
                max_candy = max(max_candy, count)
                count = 1
        max_candy = max(max_candy, count)

    return max_candy


def candy_game(board, n):
    max_candies = 0

    for i in range(n):
        for j in range(n):
            if j + 1 < n:
                board[i][j], board[i][j + 1] = board[i][j + 1], board[i][j]
                max_candies = max(max_candies, check_max(board))
                board[i][j], board[i][j + 1] = board[i][j + 1], board[i][j]

            if i + 1 < n:
                board[i][j], board[i + 1][j] = board[i + 1][j], board[i][j]
                max_candies = max(max_candies, check_max(board))
                board[i][j], board[i + 1][j] = board[i + 1][j], board[i][j]

    return max_candies


n = int(input())
board = [list(input().strip()) for _ in range(n)]

print(candy_game(board, n))
