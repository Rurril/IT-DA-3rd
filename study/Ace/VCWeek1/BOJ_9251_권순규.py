def LCS(long, short):
    answer = 0
    ll = len(long)
    sl = len(short)
    lcs = [[0] * (sl+1) for _ in range(ll+1)]
    for i in range(1,ll+1):
        for j in range(1,sl+1):
            if long[i-1] == short[j-1]:
                lcs[i][j] = lcs[i-1][j-1] + 1
            else:
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1])
    
    return lcs[ll][sl]

A = input()
B = input()
print(LCS(B,A))
