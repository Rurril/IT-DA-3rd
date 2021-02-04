import sys
from collections import deque

def bfs(start):
    q = deque()
    q.append(start)
    cnt = [-1 for i in range(N)]; cnt[start] = 0
    while q:
        start = q.popleft()
        for i in friend[start] :
            if cnt[i] == -1 :
                cnt[i] = cnt[start] + 1
                q.append(i)
    result = 0
    for i in range(N) :
        if cnt[i] != -1 :
            result += cnt[i]
    return result

N, M = map(int, sys.stdin.readline().split())
friend = [[] for i in range(N)]
res = []
for i in range(M) :
    a, b = map(int,sys.stdin.readline().split())
    friend[a-1].append(b-1)
    friend[b-1].append(a-1)

for i in range(N) :
    res.append(bfs(i))

print(res.index(min(res))+1)