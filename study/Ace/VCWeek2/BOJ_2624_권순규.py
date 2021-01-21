def func(money, idx):
    
    if money == 0:
        return 1
    if idx == k:
        return 0
    
    
    result = dp[money][idx]
    if result != -1:
        return result

    dp[money][idx] = 0
    for i in range(n[idx]+1):
        if money-p[idx]*i >= 0:
            dp[money][idx] += func(money-p[idx]*i,idx+1)
    
    return dp[money][idx]

if __name__ == "__main__":

    T = int(input())
    k = int(input())
    p=[]
    n=[]

    dp = [[-1] * k for _ in range(T+1)]

    for _ in range(k):
        a, b = map(int,input().split())
        p.append(a)
        n.append(b)

    answer = func(T,0)
    print(answer)
