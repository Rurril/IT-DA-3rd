#그대, 그머가 되어
#https://rebas.kr/815 참고
import sys
from collections import deque

def bfs():
    q = deque()
    q.append(a)
    visited = [0]*(N+1); cnt = 0
    #word[i]에 있으면 그 원소를 q에 넣고 다시 돌리기
    for i in range(a,N+1):
        while q:
            x = q.popleft()
            if x == b : return visited[x]
            for j in word[x] :
                if visited[j] == 0 :
                    q.append(j)
                    visited[j] = visited[x]+1
    return -1

a, b = map(int,sys.stdin.readline().split())
N, M = map(int,sys.stdin.readline().split())
word = [[] for i in range(N+1)]
for i in range(M):
    x,y = map(int,sys.stdin.readline().split())
    word[x].append(y)
    word[y].append(x)

print(bfs())