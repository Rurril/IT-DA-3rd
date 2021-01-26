S = list(input().split(':'))
answer = list(':0000:0000:0000:0000:0000:0000:0000:0000')
i = 0
while i < 8:
    L = len(S[i])
    if L == 0:
        if i == 7: # ~::
            # i+1 = 8이므로 index에러 나서 넣음
            break
        
        if S[i+1] == '': # ::~
            i = 1
            
        tmp = 0
        M = len(S)
        for j in range(i+1,8):
            if j < M:
                tmp += 1
            else:
                S.insert(0,'')
        i = 8 - tmp - 1
            
    else:
        for j in range(L):
            answer[5*i+(4-L)+j+1] = S[i][j]
    
    i += 1

print(''.join(answer[1:]))
