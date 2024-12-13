from collections import deque

# 입력 처리
N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

# 상하좌우 방향
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

# 빙산 위치 초기화
ice_positions = {(x, y) for x in range(N) for y in range(M) if arr[x][y] > 0}

def melt_ice():
    """빙산을 녹이는 함수."""
    global ice_positions
    new_ice_positions = set()
    changes = []

    # 현재 빙산 위치에서만 계산
    for x, y in ice_positions:
        sea_count = 0
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < N and 0 <= ny < M and arr[nx][ny] == 0:
                sea_count += 1
        # 녹은 후의 높이를 계산
        new_height = max(arr[x][y] - sea_count, 0)
        if new_height > 0:
            new_ice_positions.add((x, y))
            changes.append((x, y, new_height))
        else:
            changes.append((x, y, 0))  # 완전히 녹는 경우

    # 배열 갱신
    for x, y, new_height in changes:
        arr[x][y] = new_height

    ice_positions = new_ice_positions

def count_chunks():
    """빙산 덩어리의 개수를 세는 함수."""
    visited = [[False] * M for _ in range(N)]
    chunks = 0

    for x, y in ice_positions:
        if not visited[x][y]:
            # BFS를 사용하여 덩어리 탐색
            chunks += 1
            q = deque([(x, y)])
            visited[x][y] = True
            while q:
                cx, cy = q.popleft()
                for i in range(4):
                    nx, ny = cx + dx[i], cy + dy[i]
                    if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny] and arr[nx][ny] > 0:
                        visited[nx][ny] = True
                        q.append((nx, ny))
    return chunks

# 시뮬레이션 시작
years = 0
while True:
    melt_ice()  # 빙산 녹이기
    years += 1

    # 덩어리 개수 세기
    chunks = count_chunks()
    if chunks >= 2:
        print(years)
        break
    if not ice_positions:  # 빙산이 다 녹아 없어졌다면
        print(0)
        break
