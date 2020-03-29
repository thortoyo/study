N,K=map(int, input().split())
x = list(map(int, input().split()))

xp = []
xm = []
for i in range(N):
  if x[i] > 0:
    xp.append(x[i])
  elif x[i] < 0:
    xm.append(-x[i])
  else:
    K -= 1
xm.reverse()

ans = 1000000000
n = max(0, K - len(xp) )
for i in range(n, min(len(xm)+1,min(len(xp),K))):
  if i == 0:  m = 0
  else:       m = xm[i-1]
  ans = min(ans, m * 2 + xp[K - i - 1] )
#  print("p ",i,m,xp[K - i - 1],ans)

n = max(0, K - len(xm) )
for i in range(n, min(len(xp)+1,min(len(xm),K))):
  if i == 0:  p = 0
  else:       p = xp[i-1]
  ans = min(ans, p * 2 + xm[K - i - 1] )
#  print("m ",i,ans)
if ans == 1000000000: ans = 0
print(ans)
