from collections import deque

# 입력 처리
N = int(input())
arr = [list(input()) for _ in range(N)]

# 방향 벡터 (상, 하, 좌, 우)
dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

# BFS 함수
def bfs(x, y, visited, is_sack):
    q = deque([(x, y)])
    visited[x][y] = True
    color = arr[x][y]

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny]:
                # 적록색약인 경우와 아닌 경우 색상 비교 처리
                if is_sack:
                    if color in "RG" and arr[nx][ny] in "RG":  # R과 G를 동일하게 처리
                        visited[nx][ny] = True
                        q.append((nx, ny))
                    elif color == 'B' and arr[nx][ny] == 'B':  # B는 그대로 처리
                        visited[nx][ny] = True
                        q.append((nx, ny))
                else:
                    if arr[nx][ny] == color:  # 정상 구역 비교
                        visited[nx][ny] = True
                        q.append((nx, ny))

# 정상과 적록색약 구역 카운트
def count_areas(is_sack):
    visited = [[False] * N for _ in range(N)]
    count = 0
    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                bfs(i, j, visited, is_sack)
                count += 1
    return count

# 출력 결과
normal_count = count_areas(False)  # 정상인 경우
sack_count = count_areas(True)     # 적록색약인 경우

print(normal_count, sack_count)
