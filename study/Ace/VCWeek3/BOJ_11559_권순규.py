def down():
    for x in range(6):
        f = False
        for z in range(12):
            if Map[z][x] != '.':
                f = True
                break
        if f:
            for y in range(11,-1,-1):
                while Map[y][x] == '.':
                    flag = False
                    # 뿌요가 1개라도 있는지 검사
                    for i in range(y,-1,-1): # 가운데 -1 땜에 계속 틀림 아오 ㅡㅡ
                        if Map[i][x] != '.':
                            flag = True
                            break
                    # 뿌요가 1개라도 있으면
                    if flag:
                        # 그 칸보다 위에 있는 글자들을 한 칸씩 내려준다
                        for i in range(y,0,-1):
                            Map[i][x] = Map[i-1][x]
                        Map[0][x] = '.'
                        
                    # 없으면 멈추기
                    else:
                        break
                

def bfs(y,x,ch):
    visited = [[False] * 6 for _ in range(12)]
    visited[y][x] = True
    q = deque([[y,x]])
    dlist = [(y,x)]
    n = 1
    
    while q:
        cy, cx = q.popleft()
        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            if ny < 0 or ny == 12 or nx < 0 or nx == 6:
                continue
            if not visited[ny][nx] and Map[ny][nx] == ch:
                visited[ny][nx] = True
                q.append([ny,nx])
                dlist.append((ny,nx))
                n += 1 
    
    if n >= 4:
        for a,b in dlist:
            Map[a][b] = '.'
        return True
    else:
        return False
    

from collections import deque
dx,dy = (1,-1,0,0),(0,0,-1,1)
if __name__ == "__main__":
    Map = []
    for _ in range(12):
        tmp = []
        for ch in input():
            tmp.append(ch)
        Map.append(tmp)
    
    answer = 0
    bomb = True
    while bomb:
        bomb = False
        for y in range(11,-1,-1):
            for x in range(6):
                if Map[y][x] != '.':
                    if bfs(y,x,Map[y][x]):
                        bomb = True
        down()
        '''
        # debugging
        for m in Map:
            print(m)
        print()
        '''
        
        if bomb:
            answer += 1
        else:
            print(answer)
            break
