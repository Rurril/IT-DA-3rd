def func(y,x,flag):
    if flag:#최댓값 구하기
        if cache[y][x] != -int(1e9):
            return cache[y][x]
        
        if x-2 >= 0:
            if Map[y][x-1] == '+':
                cache[y][x] = max(cache[y][x],func(y,x-2,flag)+int(Map[y][x]))
            elif Map[y][x-1] == '*':
                cache[y][x] = max(cache[y][x],func(y,x-2,flag)*int(Map[y][x]))
            else:
                cache[y][x] = max(cache[y][x],func(y,x-2,flag)-int(Map[y][x]))
        
        if y-2 >= 0:
            if Map[y-1][x] == '+':
                cache[y][x] = max(cache[y][x],func(y-2,x,flag)+int(Map[y][x]))
            elif Map[y-1][x] == '*':
                cache[y][x] = max(cache[y][x],func(y-2,x,flag)*int(Map[y][x]))
            else:
                cache[y][x] = max(cache[y][x],func(y-2,x,flag)-int(Map[y][x]))
        
        if x-1 >= 0 and y-1 >= 0:
            if Map[y-1][x] == '+':
                cache[y][x] = max(cache[y][x],func(y-1,x-1,flag)+int(Map[y][x]))
            elif Map[y-1][x] == '*':
                cache[y][x] = max(cache[y][x],func(y-1,x-1,flag)*int(Map[y][x]))
            else:
                cache[y][x] = max(cache[y][x],func(y-1,x-1,flag)-int(Map[y][x]))
            
            if Map[y][x-1] == '+':
                cache[y][x] = max(cache[y][x],func(y-1,x-1,flag)+int(Map[y][x]))
            elif Map[y][x-1] == '*':
                cache[y][x] = max(cache[y][x],func(y-1,x-1,flag)*int(Map[y][x]))
            else:
                cache[y][x] = max(cache[y][x],func(y-1,x-1,flag)-int(Map[y][x]))
    
    else:#최솟값 구하기
        if cache[y][x] != int(1e9):
            return cache[y][x]

        if x-2 >= 0:
            if Map[y][x-1] == '+':
                cache[y][x] = min(cache[y][x],func(y,x-2,flag)+int(Map[y][x]))
            elif Map[y][x-1] == '*':
                cache[y][x] = min(cache[y][x],func(y,x-2,flag)*int(Map[y][x]))
            else:
                cache[y][x] = min(cache[y][x],func(y,x-2,flag)-int(Map[y][x]))
        
        if y-2 >= 0:
            if Map[y-1][x] == '+':
                cache[y][x] = min(cache[y][x],func(y-2,x,flag)+int(Map[y][x]))
            elif Map[y-1][x] == '*':
                cache[y][x] = min(cache[y][x],func(y-2,x,flag)*int(Map[y][x]))
            else:
                cache[y][x] = min(cache[y][x],func(y-2,x,flag)-int(Map[y][x]))
        
        if x-1 >= 0 and y-1 >= 0:
            if Map[y-1][x] == '+':
                cache[y][x] = min(cache[y][x],func(y-1,x-1,flag)+int(Map[y][x]))
            elif Map[y-1][x] == '*':
                cache[y][x] = min(cache[y][x],func(y-1,x-1,flag)*int(Map[y][x]))
            else:
                cache[y][x] = min(cache[y][x],func(y-1,x-1,flag)-int(Map[y][x]))
            
            if Map[y][x-1] == '+':
                cache[y][x] = min(cache[y][x],func(y-1,x-1,flag)+int(Map[y][x]))
            elif Map[y][x-1] == '*':
                cache[y][x] = min(cache[y][x],func(y-1,x-1,flag)*int(Map[y][x]))
            else:
                cache[y][x] = min(cache[y][x],func(y-1,x-1,flag)-int(Map[y][x]))
    
    return cache[y][x]
        

if __name__ == "__main__":
    N = int(input())
    Map = []
    
    for _ in range(N):
        Map.append(input().split())
    
    cache = [[-int(1e9)] * N for _ in range(N)]
    cache[0][0] = int(Map[0][0])
    print(func(N-1,N-1,True), end=' ')
    
    cache = [[int(1e9)] * N for _ in range(N)]
    cache[0][0] = int(Map[0][0])
    print(func(N-1,N-1,False))
