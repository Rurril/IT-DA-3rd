import heapq, sys
N = int(input())
M = int(input())
graph = [[] for _ in range(N+1)]
cost0 = []
for _ in range(M):
    s, d, c = map(int,sys.stdin.readline().split())
    if c == 0:
        cost0.append((s,d))
    else:
        graph[s].append((d,c))

for c in cost0:
    if graph[c[1]]:
        graph[c[0]] += graph[c[1]]
    else:
        graph[c[0]].append((c[1],0))

start, destination = map(int,input().split())
INF = int(1e11) # 거리의 최대값은 10^5 * 10^ 5 보다 작다

cost = [INF] * (N+1)
cost[start] = 0
q = []
heapq.heappush(q,[cost[start],start])
while q:
    current_cost, current_location = heapq.heappop(q)
    
    if cost[current_location] < current_cost:
        continue
    
    for adj, weight in graph[current_location]:
        c = current_cost + weight
        
        if c < cost[adj]:
            cost[adj] = c
            heapq.heappush(q,[c,adj])

print(cost[destination])

