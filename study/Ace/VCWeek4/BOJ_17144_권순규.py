def spread():
    global dust
    tmp_dust = [[0] * C for _ in range(R)]
    for y in range(R):
        for x in range(C):
            if dust[y][x] > 0:
                n = 4
                for i in range(4):
                    ny = y + dy1[i]
                    nx = x + dx1[i]
                    if ny < 0 or nx < 0 or ny == R or nx == C or dust[ny][nx] == -1:
                        n -= 1
                        continue
                    tmp_dust[ny][nx] += dust[y][x] // 5
                    
                tmp_dust[y][x] += dust[y][x] - (dust[y][x]//5)*n
    
    dust = tmp_dust

def cycle():
    global dust
    tmp_dust = deepcopy(dust)
    top_y = AirCleaner[0][0]
    top_x = AirCleaner[0][1]
    bot_y = AirCleaner[1][0]
    bot_x = AirCleaner[1][1]
    
    # 반시계 회전
    y = top_y
    x = top_x
    for i in range(4):
        while True:
            ny = y + dy1[i]
            nx = x + dx1[i]
            if ny < 0 or nx < 0 or ny == R or nx == C or (ny,nx) == AirCleaner[0]:
                break
            if dust[ny][nx] != -1:
                if dust[y][x] == -1:
                    tmp_dust[ny][nx] = 0
                else:
                    tmp_dust[ny][nx] = dust[y][x]
            y = ny
            x = nx
    # 시계 회전
    y = bot_y
    x = bot_x
    
    for i in range(4):
        while True:
            ny = y + dy2[i]
            nx = x + dx2[i]
            if ny < 0 or nx < 0 or ny == R or nx == C or (ny,nx) == AirCleaner[1]:
                break
            if dust[ny][nx] != -1:
                if dust[y][x] == -1:
                    tmp_dust[ny][nx] = 0
                else:
                    tmp_dust[ny][nx] = dust[y][x]
            y = ny
            x = nx
            
    tmp_dust[AirCleaner[0][0]][AirCleaner[0][1]] = -1
    tmp_dust[AirCleaner[1][0]][AirCleaner[1][1]] = -1
    dust = tmp_dust

dx1, dy1 = (1,0,-1,0),(0,-1,0,1) # 반시계
dx2, dy2 = (1,0,-1,0),(0,1,0,-1) # 시계
from copy import deepcopy
if __name__ == "__main__":
    R,C,T = map(int,input().split())
    dust = []
    AirCleaner = []
    for y in range(R):
        tmp = list(map(int,input().split()))
        for x, n in enumerate(tmp):
            if n == -1:
                AirCleaner.append((y,x))
        dust.append(tmp)
    
    for _ in range(T):
        spread()
        cycle()
    
    answer = 2
    for i in range(R):
        answer += sum(dust[i])
    
    print(answer)
    
