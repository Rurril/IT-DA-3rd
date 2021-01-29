import sys
from collections import deque

graph= []
n, m = map(int, sys.stdin.readline().split())
for i in range(n):
	graph.append(list(map(int, sys.stdin.readline().split())))
visited=[[False for i in range(m)] for _ in range(n)]
dx=[1,0,-1,0]
dy=[0,-1,0,1]

def bfs(x,y, graph):
	queue=deque()
	queue.append((x,y))
	visited[x][y]=True
	while queue:
		x,y = queue.popleft()
		for i in range(4):
			nx=x+dx[i]
			ny=y+dy[i]
			if 0<=nx<n and 0<=ny<m:
				if not visited[nx][ny] and graph[nx][ny]!=0:
					min_distance=1001
					for j in range(4):
						n2x = nx+dx[j]
						n2y = ny+dy[j]
						#nx,ny좌표를 방문했을경우만 min distance 탐색
						if 0<=n2x<n and 0<=n2y<m and visited[n2x][n2y]:
							min_distance=min(min_distance, graph[n2x][n2y]+1)
					graph[nx][ny]=min_distance
					visited[nx][ny]=True
					queue.append((nx,ny))
				
flag=True
#포문에서 한번 탐색하면 끝나야하는데 flag를 안쓰고 탈출할 수 있는 방법이 있을까?
for i in range(n):
	for j in range(m):
		#break가 없으면 graph[i][j]인 모든 경로를 다 탐색한다 꼭 필요!
		if graph[i][j]==2:
			graph[i][j]=0
			bfs(i,j,graph)
			flag=False
			break
	if not flag: break
#이런식으로 하면 편할듯!!
# for i in range(n):
#     for j in range(m):
#         if a[i][j] == 2:
#             q.append((i, j))
#             a[i][j] = 2
#             break
# bfs()
		
for i in range(n):
	for j in range(m):
		print(-1 if not visited[i][j] and graph[i][j]!=0 else graph[i][j] , end=" ")
	print()