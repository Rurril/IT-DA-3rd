#점프 게임
#https://rebas.kr/775 참고
import sys
from collections import deque

def bfs() :
    q = deque()
    #첫 시작인 location[0][0]
    q.append([0,0])
    while q :
        #x : left or right / y : 0~N
        x, y = q.popleft()
        for nx, ny in (x, y-1), (x, y+1), (not x, y+k):
            if ny >= N : return 1
            if 0 <= nx < 2 and 0 <= ny < N and location[nx][ny] == '1' and visited[nx][ny] == 0 :
                visited[nx][ny] = 1
                q.append([nx, ny])
    # for i in range(n):
    #     for j in range(len(q)):
    #         x, y = q.popleft()
    #         for nx, ny in (x, y-1), (x, y+1), (not x, y+k):
    #             if ny >= n:
    #                 print(1)
    #                 return
    #             if ny > i and not check[nx][ny] and a[nx][ny] == '1':
    #                 q.append((nx, ny))
    #                 check[nx][ny] = True
    return 0

#안전한 칸 : Safe (이동가능), 위험한 칸 : Danger (이동불가)
#왼쪽 줄의 1번 칸은 항상 안전한 칸
N, k = map(int,sys.stdin.readline().split())
location = [list(sys.stdin.readline().strip()) for _ in range(2)]
visited = [[0]*(N) for i in range(2)]
#좌표 : left는 location[0]에, right은 location[1]에
print(bfs())