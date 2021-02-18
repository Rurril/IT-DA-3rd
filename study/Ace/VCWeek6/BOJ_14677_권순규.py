# 틀려서 모르겠음
def bfs():
    visited = [-1] * (N+1)
    
    q = deque([[N,0,0,N-1,0]])
    
    while q:
        location, n, start, end, i = q.popleft()

        if start < N and n > visited[start] and med[start] == order[i]:
            visited[start] = n+1
            q.append((start,n+1,start+1,end,(i+1)%3))
            
        if end >= 0 and n > visited[end] and med[end] == order[i]:
            visited[end] = n+1
            q.append((end,n+1,start,end-1,(i+1)%3))
            
        #print(visited)
    
    return max(visited)
        
        

from collections import deque
if __name__ == "__main__":
    N = int(input()) * 3
    med = input()
    order = 'BLD'
    print(max(bfs(),0))
