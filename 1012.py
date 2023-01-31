n = int(input())
k = int(input())
dp = []
for i in range(n):
    dp.append([0,0])
dp[0][1] = k-1
for i in range(1,n):
    dp[i][0] = dp[i-1][1]
    dp[i][1] = (dp[i-1][1]+ dp[i-1][0])*(k-1)
print(dp[n-1][0] + dp[n-1][1])
