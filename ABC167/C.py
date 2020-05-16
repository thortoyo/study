N,M,X=map(int,input().split())
C = [0] * N
A = [ [0 for i in range(M)] for i in range(N) ]
for i in range(N):
  CA = list(map(int,input().split()))
  C[i] = CA[0]
  A[i] = CA[1:]
INF = 100000000
ans = INF
for i in range( 1 << N ):
  cost = 0
  r = [0] * M
  for j in range(N):
    if (i & (1 << j) != 0):
      cost += C[j]
      for k in range(M):
        r[k] += A[j][k]
  ok = 1
  for k in range(M):
    if r[k] < X:
      ok = 0
  if ok == 1:
    ans = min(ans, cost)
#  print(" ",i," ",ok)
#  print(" ",r)
if ans == INF:
  print("-1")
else:
  print(ans)


