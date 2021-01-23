dx=[0,1,0,-1]
dy=[1,0,-1,0]

n= int(input())
arr=list()
for i in range(n):
	x = y = 0
	max_x=max_y=0
	min_x=min_y=0
	a=0
	nx=0
	ny=1
	arr=list(map(str, input()))
	for j in range(len(arr)):
		if arr[j] == 'R':
			if a==3: a=0
			else: a+=1
			nx = dx[a]
			ny = dy[a]
		if arr[j] == 'L':
			if a==0: a=3
			else: a-=1
			nx = dx[a]
			ny = dy[a]
		if arr[j]=='F':
			x=x+nx
			y=y+ny
		if arr[j]=='B':
			x=x-nx
			y=y-ny
		max_x = max(max_x, x)
		min_x = min(min_x, x)
		max_y = max(max_y, y)
		min_y = min(min_y, y)
	print(abs((max_x-min_x)*(max_y-min_y)))



