D,G=map(int, input().split())
G //= 100
dp = [ [ 0 for i in range(1105) ] for i in range(12) ]
for i in range(1,D+1):
  p, c = map(int, input().split())
  c //= 100
  for j in range(1005):
    for k in range(p):
      dp[i][j+k] = max( dp[i][j+k], dp[i-1][j] + k*i)
    dp[i][j+p] = max( dp[i][j+p], dp[i-1][j] + p*i + c)

for i in range(1001):
  if dp[D][i] >= G:
    print(i)
    break

#for j in range(23):
#  print(j,dp[0][j],dp[1][j],dp[2][j])

