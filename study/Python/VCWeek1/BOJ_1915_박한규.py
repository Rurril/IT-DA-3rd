import sys
read = sys.stdin.readline

n, m = map(int, read().split())
# [[0]*(m+1)]*(n+1)로 하면 첫 라인이 복사가 됨
dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
long = 0
data = []
for i in range(n):
    data.append(list(map(int, list(read().strip()))))

for i in range(1, n+1):
    for j in range(1, m+1):
        if data[i-1][j-1] == 1:
            dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
            if dp[i][j] > long:
                long = dp[i][j]
print(long**2)
