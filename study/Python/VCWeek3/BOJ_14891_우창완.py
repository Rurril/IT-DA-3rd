

#2차원 배열을 만들어서 풀었으면 더 코드가 깔끔했을듯,,ㅍㅠㅠㅠㅠ
#간단한 구현 문제


def rotate(num, wheel, dirt):
	#시계방향 회전
	visited[num] = True
	if dirt == 1:
		for i in range(8):
			if i == 7:
				wheel[0] = wheel[i]
			else:
				wheel[i+1] = wheel[i]
	elif dirt == -1:
		for i in range(8):
			if i == 7:
				wheel[i] = wheel[0]
			else:
				wheel[i] = wheel[i+1]
	if num == 2 or num == 3:
		if wheel[num][2] != wheel[num-1][6]:
			if not visited[num-1]:
				rotate(num-1, wheel[num-1], 1 if dir == -1 else -1)
		if wheel[num][6] != wheel[num+1][2]:
			if not visited[num+1]:
				rotate(num+1, wheel[num+1], 1 if dir == -1 else -1)
	else:
		if num == 1:
			if wheel[num][2] != wheel[num+1][6]:
				rotate(num+1, wheel[num+1], 1 if dir == -1 else -1)
		elif num == 4:
			if wheel[num][6] != wheel[num-1][2]:
				rotate(num-1, wheel[num-1], 1 if dir == -1 else -1)

visited=[False for _ in range(4)]
wheel=[[0 for _ in range(8)] for _ in range(4)]
for i in range(4):
	wheel[i]= list(map(int, input()))
print(wheel)
k=int(input())

for i in range(k):
	#num: 톱니바퀴 번호 dir: 방향 1: 시계방향 -1 반시계 방향
	num, dir = map(int, input().split(" "))
	rotate(num, wheel[num], dir)




	

# for i in range(k):
# 	#num: 톱니바퀴 번호 dir: 방향 1: 시계방향 -1 반시계 방향
# 	num, dir = map(int, input().split(" "))
# 	if num==1:
# 		rotate(wheel1,dir)
# 		#2번이랑 6번이 다른 극일 경우: 반대방향
# 		if wheel1[2]!=wheel2[6]:
# 			rotate(wheel2, 1 if dir==-1 else -1)
# 	elif num==2:
# 		rotate(wheel2, dir)
# 		if wheel1[6] != wheel2[2]:
# 			rotate(wheel1, 1 if dir == -1 else -1)
# 		if wheel2[6] != wheel3[2]:
# 			rotate(wheel3, 1 if dir == -1 else -1)
# 	elif num==3:
# 		rotate(wheel3, dir)
# 		if wheel2[6] != wheel3[2]:
# 			rotate(wheel2, 1 if dir == -1 else -1)
# 		if wheel3[6] != wheel4[2]:
# 			rotate(wheel4, 1 if dir == -1 else -1)
# 	else:
# 		rotate(wheel4, dir)
# 		if wheel3[6] != wheel4[2]:
# 			rotate(wheel3, 1 if dir == 0 else 1)
	
# total=0
# if wheel1[0]==1: total+=1
# if wheel2[0]==1: total+=2
# if wheel3[0]==1: total+=4
# if wheel4[0]==1: total+=8
# print(total)

