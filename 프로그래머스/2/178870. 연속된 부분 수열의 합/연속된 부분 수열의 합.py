def solution(sequence, k):
    answer = []
    n = len(sequence)
    left, right = 0, 0
    current_sum = sequence[0]
    
    min_length = n + 1
    best_start, best_end = 0, 0
    
    while left <= right and right < n:
        if current_sum == k:
            window_length = right - left + 1
            
            if window_length < min_length:
                min_length = window_length
                best_start, best_end = left, right
                
            # elif window_length == min_length and left < best_start:
            #     best_start, best_end = left, right

            current_sum -= sequence[left]
            left += 1
        elif current_sum < k:
            right += 1
            if right < n:
                current_sum += sequence[right]
        else:
            current_sum -= sequence[left]
            left += 1
    
    return [best_start, best_end]
