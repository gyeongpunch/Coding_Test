from collections import deque

N, K = map(int, input().split())
visited = [-1]*100001

def bfs(now, target):
    q = deque([now])
    visited[now] = 0

    while q:
        x = q.popleft()
        next_pos = [x+1, x-1, x*2]
        for np in next_pos:
            if 0<=np<100001 and visited[np]==-1:
                q.append(np)
                visited[np] = visited[x] + 1
    return visited[target]


result = bfs(N, K)

# print(visited[:50])
lst = deque([K])
while True:
    # print(lst)
    if lst[0]%2==0:
        next_pos = [lst[0]+1, lst[0]-1, lst[0]//2]
    else:
        next_pos = [lst[0]+1, lst[0]-1]
    # print(next_pos)
    for np in next_pos:
        # print()
        # print('lst[0]: ', lst[0])
        # print('np: ', np)
        # print()
        if 0<=np<100001 and visited[lst[0]]-1 == visited[np]:
            lst.appendleft(np)
            break
    if lst[0]==N:
        break

print(result)
print(*lst)
