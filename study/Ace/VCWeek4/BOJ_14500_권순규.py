# 노가다 문제 ㅗ
def f(y,x):
    answer = 0
    possible = []
    # 1번 모양
    for i in range(4):
        flag = True
        for j in range(3):
            ny = y + shape1[i][j][0]
            nx = x + shape1[i][j][1]
            if ny < 0 or nx < 0 or ny >= N or nx >= M:
                flag = False
                break
        
        if flag:
            possible.append(i)
    
    for p in possible:
        tmp = nums[y][x]
        for i in range(3):
            tmp += nums[y+shape1[p][i][0]][x+shape1[p][i][1]]
        answer = max(answer,tmp)
    
    possible = []
    # 2번 모양
    for i in range(8):
        flag = True
        for j in range(3):
            ny = y + shape2[i][j][0]
            nx = x + shape2[i][j][1]
            if ny < 0 or nx < 0 or ny >= N or nx >= M:
                flag = False
                break
        
        if flag:
            possible.append(i)
    
    for p in possible:
        tmp = nums[y][x]
        for i in range(3):
            tmp += nums[y+shape2[p][i][0]][x+shape2[p][i][1]]
        answer = max(answer,tmp)
    
    possible = []
    # 3번 모양
    for i in range(8):
        flag = True
        for j in range(3):
            ny = y + shape3[i][j][0]
            nx = x + shape3[i][j][1]
            if ny < 0 or nx < 0 or ny >= N or nx >= M:
                flag = False
                break
        
        if flag:
            possible.append(i)
    
    for p in possible:
        tmp = nums[y][x]
        for i in range(3):
            tmp += nums[y+shape3[p][i][0]][x+shape3[p][i][1]]
        answer = max(answer,tmp)
    
    possible = []
    # 4번 모양    
    for i in range(4):
        flag = True
        for j in range(3):
            ny = y + shape4[i][j][0]
            nx = x + shape4[i][j][1]
            if ny < 0 or nx < 0 or ny >= N or nx >= M:
                flag = False
                break
        
        if flag:
            possible.append(i)
    
    for p in possible:
        tmp = nums[y][x]
        for i in range(3):
            tmp += nums[y+shape4[p][i][0]][x+shape4[p][i][1]]
        answer = max(answer,tmp)
    
    possible = []
    # 5번 모양
    for i in range(4):
        flag = True
        for j in range(3):
            ny = y + shape5[i][j][0]
            nx = x + shape5[i][j][1]
            if ny < 0 or nx < 0 or ny >= N or nx >= M:
                flag = False
                break
        
        if flag:
            possible.append(i)
    
    for p in possible:
        tmp = nums[y][x]
        for i in range(3):
            tmp += nums[y+shape5[p][i][0]][x+shape5[p][i][1]]
        answer = max(answer,tmp)
    
    return answer

if __name__ == "__main__":

    N, M = map(int,input().split())
    nums = []
    for _ in range(N):
        nums.append(list(map(int,input().split())))
    shape1 = [[(1,0),(2,0),(3,0)],[(0,1),(0,2),(0,3)],[(-1,0),(-2,0),(-3,0)],[(0,-1),(0,-2),(0,-3)]] # ---- 4방
    shape2 = [[(1,0),(2,0),(2,1)],[(1,0),(2,0),(2,-1)],[(0,1),(0,2),(1,2)],[(0,1),(0,2),(-1,2)],[(-1,0),(-2,0),(-2,-1)],[(-1,0),(-2,0),(-2,1)],[(0,-1),(0,-2),(1,-2)],[(0,-1),(0,-2),(-1,-2)]] # L, 8방
    shape3 = [[(1,0),(1,1),(2,1)],[(1,0),(1,-1),(2,-1)],[(0,1),(1,1),(1,2)],[(0,1),(-1,1),(-1,2)],[(-1,0),(-1,-1),(-2,-1)],[(-1,0),(-1,1),(-2,1)],[(0,-1),(-1,-1),(-1,-2)],[(0,-1),(1,-1),(1,-2)],] # ㄴㄱ, 8방
    shape4 = [[(1,0),(-1,0),(0,1)],[(0,1),(0,-1),(1,0)],[(-1,0),(1,0),(0,-1)],[(0,-1),(0,1),(-1,0)]] # ㅜ, 4방
    shape5 = [[(1,0),(0,1),(1,1)],[(0,1),(1,0),(1,1)],[(-1,0),(0,-1),(-1,-1)],[(0,-1),(-1,0),(-1,-1)]] # ㅁ, 4방
    answer = 0
    for y in range(N):
        for x in range(M):
            answer = max(answer,f(y,x))
    print(answer)
