def bfs():
    visited = [[False] * m for _ in range(n)]
    visited[start[0]][start[1]] = True
    q = deque([[start,0]])
    time = -1
    while q:
        (y,x), t = q.popleft()
        if 3 <= Map[y][x] <= 5:
            time = t
            break
        
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if ny < 0 or nx < 0 or ny == n or nx == m or Map[ny][nx] == 1:
                continue
            if not visited[ny][nx]:
                visited[ny][nx] = True
                q.append([(ny,nx),t+1])
    
    return time

dx, dy = (1,-1,0,0),(0,0,-1,1)
from collections import deque
if __name__ == "__main__":
    n, m = map(int,input().split())
    start = []
    Map = []
    for y in range(n):
        tmp = list(map(int,input()))
        for x, i in enumerate(tmp):
            if i == 2:
                start = (y,x)
        Map.append(tmp)
    
    answer = bfs()
    if answer > 0:
        print('TAK')
        print(answer)
    else:
        print('NIE')
