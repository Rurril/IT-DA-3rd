#윌리암슨수액빨이딱따구리가 정보섬에 올라온 이유
#https://github.com/surinoel/boj/blob/master/17129.cpp 참고
import sys
from collections import deque

def bfs(start):
    q = deque()
    q.append(start)
    visited[start[0]][start[1]] = 1
    m3x, m3y, m4x, m4y, m5x, m5y = 0, 0, 0, 0, 0, 0
    cnt = 0
    while q:
        x, y = q.popleft()
        if island[x][y] == 3 :
            m3x = x; m3y = y
        elif island[x][y] == 4:
            m4x = x; m4y = y
        elif island[x][y] == 5:
            m5x = x; m5y = y
        for i in range(4) :
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and visited[nx][ny] == 0 and island[nx][ny] != 1:
                q.append([nx,ny])
                visited[nx][ny] = visited[x][y] + 1
                cnt += 1
    dist = min(visited[m3x][m3y], min(visited[m4x][m4y], visited[m5x][m5y]))-1
    if dist != 0 :
        print("TAK")
        print(dist)
    else :
        print("NIE")

n, m = map(int,sys.stdin.readline().split())
island = [list(sys.stdin.readline().rstrip('\n')) for i in range(m)]
visited = [[0]*(n) for i in range(m)]
start = []
for i in range(n) :
    for j in range(m) :
        island[i][j] = int(island[i][j])
        if island[i][j] == 2 :
            start.append(i)
            start.append(j)
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

bfs(start)