def solution(sequence, k):
    answer = []
    
    length = len(sequence)
    start, end = length-1, length-1
    curr = sequence[length-1]
    
    print(length)
    
    mx_l = length
    
    while start != -1 and end != -1:
        if curr < k:
            start -= 1
            curr += sequence[start]
        elif curr > k:
            curr -= sequence[end]
            end -= 1
        else:
            if end - start <= mx_l:
                answer = [start, end]
                mx_l = end - start
            start -= 1
            curr += sequence[start]
    
    return answer