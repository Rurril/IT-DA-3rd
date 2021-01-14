from collections import deque

S = int(input())
Time = [[False] * 2000 for _ in range(2000)]

Time[1][0]=True
q = deque([[2,2,1]])
answer = 0

while q:
    cur, t, clip = q.popleft()
    if cur == S:
        answer = t
        break
    
    if not Time[cur][clip]:
        Time[cur][clip] = True
            
        if cur < S:
            # 복사
            q.append([cur,t+1,cur])
            # 붙여넣기
            q.append([cur+clip,t+1,clip])
        
        if cur > 2:
            q.append([cur-1,t+1,clip])
print(answer)
