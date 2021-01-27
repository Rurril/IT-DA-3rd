import sys

r, c = map(int, sys.stdin.readline().split())
sea=list()
for i in range(r):
	sea.append(list(map(str,sys.stdin.readline().strip())))

graph=[[0 for _ in range(c)] for _ in range(r)]
for i in range(r):
	for j in range(c):
		if sea[i][j]=='X':
			if i+1>=r or sea[i+1][j]=='.' : graph[i][j]+=1
			if i-1<0 or sea[i-1][j]=='.': graph[i][j]+=1
			if j+1>=c or sea[i][j+1]=='.': graph[i][j]+=1
			if j-1<0 or sea[i][j-1]=='.': graph[i][j]+=1

for i in range(r):
	for j in range(c):
		if graph[i][j]>=3 and sea[i][j]=='X':
			sea[i][j]='.'
min_x=r
max_x= max_y=0
min_y=c

for i in range(r):
	for j in range(c):
		if sea[i][j]=='X':
			min_x=min(min_x,i)
			max_x=max(max_x,i)
			min_y=min(min_y,j)
			max_y=max(max_y,j)

for i in range(min_x,max_x+1):
	for j in range(min_y, max_y+1):
		print(sea[i][j], end='')
	print()