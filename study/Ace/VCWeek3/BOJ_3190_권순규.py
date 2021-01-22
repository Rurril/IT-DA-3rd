n = int(input())
k = int(input())
data = [[0] * (n+1) for _ in range(n+1)]
info = []

# 사과 있는 곳을 1로 표시
for _ in range(k):
    a, b = map(int,input().split())
    data[a][b]=1
    
# 방향 회전 정보 입력
l = int(input())
for _ in range(l):
    x, c = input().split()
    info.append((int(x),c))

# 처음에는 오른쪽을 보고 있으므로 (동, 남, 서, 북)
dx, dy = (0,1,0,-1),(1,0,-1,0)

def turn(direction, c):
    if c == "L":
        direction = (direction -1)%4
    else:
        direction = (direction +1)%4
    return direction

def simulate():
    x, y = 1,1 # 뱀의 머리 위치
    data[x][y] = 2 # 뱀이 존재하는 위치=2
    direction = 0# 처음에는 동쪽
    time = 0
    index = 0# 다음 회전 정보
    q = [(x,y)]# 큐
    while True:
        nx = x + dx[direction]
        ny = y + dy[direction]

        # 맵 범위 안에 있고, 뱀의 몸통이 없는 위치라면
        if 1 <= nx <= n and 1 <= ny <= n and data[nx][ny] != 2:
            # 사과가 없다면 이동 후에 꼬리 제거
            if data[nx][ny] == 0:
                data[nx][ny] = 2
                q.append((nx,ny))
                tx, ty = q.pop(0)
                data[tx][ty] = 0
            # 사과가 있으면 이동 후에 꼬리 그대로 두기
            if data[nx][ny] == 1:
                data[nx][ny] = 2
                q.append((nx,ny))
        # 벽이나 몸에 부딪힌 경우
        else:
            time += 1
            break
        y,x = ny,nx
        time += 1
        # 회전할 시간인 경우 회전하기
        if index < l and time == info[index][0]:
            direction = turn(direction,info[index][1])
            index += 1
    return time

print(simulate())
    
