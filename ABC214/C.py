N = int(input())
S = list(map(int, input().split()))
T = list(map(int, input().split()))
dp = [ 0 for _ in range(N) ]
for i in range(N):
  dp[i] = T[i]
for i in range(N-1):
  if dp[i+1] > dp[i] + S[i]:
    dp[i+1] = dp[i] + S[i]
if dp[0] > dp[N-1] + S[N-1]:
  dp[0] = dp[N-1] + S[N-1]
for i in range(N-1):
  if dp[i+1] > dp[i] + S[i]:
    dp[i+1] = dp[i] + S[i]
for i in range(N):
  print(dp[i])

