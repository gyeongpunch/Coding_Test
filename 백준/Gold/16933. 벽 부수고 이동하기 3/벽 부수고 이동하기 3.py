from collections import deque

def bfs():
    d = deque([(0, 0, 0, 1)])  # (벽 부순 횟수, x 좌표, y 좌표, 현재 거리)
    visited[0][0][0] = 1  # 시작점 방문 처리

    while d:
        ck, cn, cm, dist = d.popleft()  # 벽 부순 횟수, x, y, 거리
        # 도착지에 도달한 경우
        if cn == N - 1 and cm == M - 1:
            return dist

        # 현재 낮/밤 상태
        day = dist % 2  # 1: 낮, 0: 밤

        # 4방향 탐색
        for dn, dm in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
            nn, nm = cn + dn, cm + dm

            if 0 <= nn < N and 0 <= nm < M:
                # 일반 탐색: 빈 칸
                if visited[ck][nn][nm] == 0 and arr[nn][nm] == 0:
                    visited[ck][nn][nm] = dist
                    d.append((ck, nn, nm, dist + 1))

                # 벽 부수기
                elif ck < K and arr[nn][nm] == 1 and visited[ck + 1][nn][nm] == 0:
                    if day:  # 낮에만 벽을 부술 수 있음
                        visited[ck + 1][nn][nm] = dist
                        d.append((ck + 1, nn, nm, dist + 1))
                    else:  # 밤에는 대기
                        d.append((ck, cn, cm, dist + 1))  # 대기

    # 도착할 수 없는 경우
    return -1


# 입력 처리
N, M, K = map(int, input().split())
arr = [list(map(int, input().strip())) for _ in range(N)]

# 방문 배열: visited[벽 부순 횟수][x][y]
visited = [[[0 for _ in range(M)] for _ in range(N)] for _ in range(K + 1)]

# 결과 출력
print(bfs())