

#2차원 배열을 만들어서 풀었으면 더 코드가 깔끔했을듯,,ㅍㅠㅠㅠㅠ
#간단한 구현 문제
#python의 장점인 짧은 코딩 적용 전후 버젼!

def rotate(num, dirt):
	visited[num] = True
	if num == 2 or num == 3:
		#n극과 s극이 붙어있는 상황
		if wheel[num][2] != wheel[num+1][6]:
			if not visited[num+1]:
				rotate(num+1, 1 if dirt == -1 else -1)
		if wheel[num][6] != wheel[num-1][2]:
			if not visited[num-1]:
				rotate(num-1, 1 if dirt == -1 else -1)
	else:
		if num == 1:
			if wheel[num][2] != wheel[num+1][6]:
				if not visited[num+1]:
					rotate(num+1, 1 if dirt == -1 else -1)
		elif num == 4:
			if wheel[num][6] != wheel[num-1][2]:
				if not visited[num-1]:
					rotate(num-1, 1 if dirt == -1 else -1)

	#시계방향
	if dirt == 1:
		temp=wheel[num][7]
		for i in range(7,0, -1):
			wheel[num][i]=wheel[num][i-1]
		wheel[num][0]=temp
	elif dirt == -1:
		temp=wheel[num][0]
		for i in range(7):
			wheel[num][i]=wheel[num][i+1]
		wheel[num][7]=temp
	
	#효율적인 코딩
	# if direction==1:
	# 	#슬라이싱 꿀팁
	# 	temp=wheel[num][-1]
	# 	wheel[num][1:]=wheel[1][:-1]
	# 	wheel[num][0]=temp
	# else:
	# 	temp=wheel[num][0]
	# 	wheel[num][:-1]=wheel[num][1:]
	# 	wheel[num][-1]=temp
	#진짜 예술이다,,, 
	# for x in [num+1, num-1]:
    #     if 0 <= x < 4 and not visit[x]:
    #         visit[x] = True
    #         if x == (num+1):
    #             if to_right != topni[x][6]:
    #                 rotate(x, direction*-1)

    #         else:
    #             if to_left != topni[x][2]:
    #                 rotate(x, direction*-1)


	


	
wheel=[[0 for _ in range(8)] for _ in range(5)]
for i in range(1,5):
	wheel[i]= list(map(int, input()))

k=int(input())

for i in range(k):
	#num: 톱니바퀴 번호 dir: 방향 1: 시계방향 -1 반시계 방향
	visited = [False]*5
	num, dir = map(int, input().split(" "))
	rotate(num , dir)
sum=0

# if wheel[1][0]==1: sum+=1
# if wheel[2][0]==1: sum+=2
# if wheel[3][0]==1: sum+=4
# if wheel[4][0]==1: sum+=8
for i in range(1,5):
	sum+= 
		
	
print(sum)




	
