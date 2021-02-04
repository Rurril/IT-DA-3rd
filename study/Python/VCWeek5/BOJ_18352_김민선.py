import sys
from collections import deque

def bfs() :
    res = [-1] * (N+1)
    res[X] = 0; q = deque([X])
    while q :
        now = q.popleft()
        for next in city[now]:
            if res[next] == -1 :
                res[next] = res[now] + 1
                q.append(next)
    for i in range(N+1):
        if res[i] == K : print(i)
    if K not in res : print(-1) 

N,M,K,X = map(int, sys.stdin.readline().split())
city = [[] for i in range(N+1)]
for i in range(M) :
    a, b = map(int,sys.stdin.readline().split())
    #각 도시 번호에 연결된 도시를 넣을 수 있음
    city[a].append(b)
bfs()