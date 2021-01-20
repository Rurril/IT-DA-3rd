import sys
n=12
m=6
square=[[0 for _ in range(m)] for j in range(n)]
visited = [[False for _ in range(m)] for j in range(n)]
for i in range(n):
	square[i]=list(map(str, input()))


result=0
colors=['R','G','B','P','Y']
dx=[1,0,-1,0]
dy=[0,-1,0,1]
# #뿌요가 터지는 순서도 영향을 미치나?

result=0
cnt=0
def dfs(color, x,y):
	global cnt
	cnt+=1
	visited[x][y] = True
	for i in range(4):
		nx = x+dx[i]
		ny = y + dy[i]
		if 0 <= nx < n and 0 <= ny < m:
			if square[nx][ny]==color and not visited[nx][ny]:
				dfs(color, nx, ny)


def bomb(color, x, y):
	square[x][y] = None
	for i in range(4):
		nx = x+dx[i]
		ny = y + dy[i]
		if 0 <= nx < n and 0 <= ny < m:
			if square[nx][ny]==color and visited[nx][ny]:
				bomb(color, nx, ny)

def fall():
	for i in reversed(range(n)):
		for j in reversed(range(m)):
			if square[i][j]==None:
				for k in reversed(range(n)):
					if k==0: square[k][j]='.'
					else: square[k][j]=square[k-1][j]



for i in range(n):
	for j in range(m):
		if square[i][j] != '.' and not visited[i][j]:
			visited = [[False for _ in range(m)] for j in range(n)]
			cnt=0
			dfs(square[i][j], i, j)
			if cnt>=4: 
				result+=1
				bomb(square[i][j], i ,j)
				for _ in range(cnt):
					fall()
				
print(result)




