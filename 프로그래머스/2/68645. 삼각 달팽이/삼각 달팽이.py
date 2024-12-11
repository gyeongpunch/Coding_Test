def solution(n):
    answer = []
    triangle = [[0]*i for i in range(1, n+1)]
    
    # print(triangle)
    x, y = -1, 0
    cnt = 1
    total_cnt = n*(n+1)//2
    length = n
    state = 0
    
    while cnt <= total_cnt:
        if state == 0:
            for _ in range(length):
                x += 1
                triangle[x][y] = cnt
                cnt += 1
                
        elif state == 1:
            for _ in range(length):
                y += 1
                triangle[x][y] = cnt
                cnt += 1
                
        else:
            for _ in range(length):
                x -= 1
                y -= 1
                triangle[x][y] = cnt
                cnt += 1
                
        state = (state + 1) % 3
        length -= 1
    
    for i in range(n):
        for num in triangle[i]:
            answer.append(num)
    #         print(i)
    # print(triangle)
    return answer