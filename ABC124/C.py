s=list(input())
dp=[[0,0] for i in range(len(s)+1)]
dp[0][1] = 1
for i in range( len(s)-1 ):
  if s[i] == s[i+1]:
    dp[i+1][0] = dp[i][1]
    dp[i+1][1] = dp[i][0]+1
  else:
    dp[i+1][0] = dp[i][0]
    dp[i+1][1] = dp[i][1]+1
print(min(dp[len(s)-1]))  
