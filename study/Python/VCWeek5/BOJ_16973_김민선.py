import sys
from collections import deque

# 이해를 못하겠음
# def isEmpty() :
#     for i in range(N):
#         for j in range(M):
#             if N - H < i:
#                 emptyChk[i][j] = 0
#             if M - W < j:
#                 emptyChk[i][j] = 0
#             if kan[i][j] == 1: # 벽이 있으면
#                 for k in range(i - H + 1, i + 1):
#                     for l in range(j - W + 1, j + 1):
#                         if 0 <= k < N and 0 <= l < M:
#                             emptyChk[k][l] = 0

def bfs():
    #isEmpty()
    q = deque()
    q.append([Sr, Sc, 0]); visit[Sr][Sc] = 1
    ans = -1
    while q :
        y, x, cnt = q.popleft()
        if y == Fr and x == Fc :
            ans = cnt
            break
        for i in range(4) :
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < M and 0 <= ny < N :
                if 0 <= ny + H - 1 < N and nx + W - 1 < M and visit[ny][nx] == 0 :
                    if emptyChk[ny][nx] :
                        q.append([ny, nx, cnt+1])
                        visit[ny][nx] = 1
    return ans

N, M = map(int, sys.stdin.readline().split())
kan = [list(map(int, input().split())) for i in range(N)]
H, W, Sr, Sc, Fr, Fc = map(int, sys.stdin.readline().split())
#(1,1)로 시작하니까 1씩 뺀 값으로 생각
Sr, Sc, Fr, Fc = Sr - 1, Sc - 1, Fr - 1, Fc - 1
visit = [[0 for j in range(M)] for i in range(N)]
emptyChk = [[1 for j in range(M)] for i in range(N)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

print(bfs())