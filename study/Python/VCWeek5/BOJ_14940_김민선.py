import sys
from collections import deque

def bfs(a, b) :
    q = deque()
    q.append([a,b])
    maps[a][b] = 2
    while q :
        x,y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < M and maps[nx][ny] == 1:
                q.append([nx,ny])
                maps[nx][ny] = maps[x][y] + 1
    for i in range(N):
        for j in range(M):
            d = maps[i][j]
            sys.stdout.write("%d " % (d-2 if d else 0))
        sys.stdout.write("\n")

N, M = map(int, sys.stdin.readline().split())
maps = [list(map(int, input().split())) for i in range(N)]
start_a = 0; start_b = 0
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for i in range(N) :
    for j in range(M):
        if maps[i][j] == 2 :
            start_a = i; start_b = j
            break

bfs(start_a, start_b)
