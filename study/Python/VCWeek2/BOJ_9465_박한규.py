import sys
read = sys.stdin.readline


for i in range(int(read())):
    st = []
    n = int(input())
    for _ in range(2):
        st.append(list(map(int, read().split())))
    st[0][1] += st[1][0]
    st[1][1] += st[0][0]
    for j in range(2, n):
        st[0][j] += max(st[1][j - 1], st[1][j - 2])
        st[1][j] += max(st[0][j - 1], st[0][j - 2])
    print(max(st[0][n - 1], st[1][n - 1]))


# 첫 번째 시도 실패
# 윗 칸에서 시작할 때랑 아랫 칸에서 시작할 때를 비교하면서 더해줬음
# 막상 진행하고 보니 Greedy 알고리즘 처럼 진행돼서 실패..

# import sys
# read = sys.stdin.readline

# def calc(x, y):
# 	i, j = x, y
# 	sum = st[i][j]
# 	while j < n-1:
# 		if i==0:
# 			if st[i+1][j+1]+st[i][j+2] >= st[i+1][j+2]:
# 				sum += st[i+1][j+1]+st[i][j+2]
# 				j += 2
# 			else:
# 				sum += st[i+1][j+2]
# 				i += 1
# 				j += 2
# 		elif i==1:
# 			if st[i-1][j+1]+st[i][j+2] >= st[i-1][j+2]:
# 				sum += st[i-1][j+1]+st[i][j+2]
# 				j += 2
# 			else:
# 				sum += st[i-1][j+2]
# 				i -= 1
# 				j += 2
# 	return sum


# for _ in range(int(read())):
# 	n = int(read())
# 	st = [[int(0) for _ in range(n)] for _ in range(2)]
# 	st[0] = list(map(int, read().split()))
# 	st[0].append(0)		# n이 짝수일 때를 대비해 0 추가
# 	st[1] = list(map(int, read().split()))
# 	st[1].append(0)
# 	# for i in range(2):
# 	# 	for j in range(n):
# 	# 		print(st[i][j], end=' ')
# 	res1 = calc(0, 0)
# 	res2 = calc(1, 0)
# 	if res1 >= res2 :
# 		print(res1)
# 	else:
# 		print(res2)
