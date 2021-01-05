import sys
read = sys.stdin.readline

str1 = read().strip()
str2 = read().strip()
dp = [[0]*(len(str2)+1) for _ in range(len(str1)+1)]
for i in range(len(str1)):
    for j in range(len(str2)):
        if str1[i] == str2[j]:
            dp[i+1][j+1] = dp[i][j] + 1
        else:
            dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])
print(dp[len(str1)][len(str2)])
