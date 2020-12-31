H,W=map(int,input().split())
A = [ [ 0 for _ in range(W)] for _ in range(H) ]
mi = 1000
for i in range(H):
  A[i]=list(map(int, input().split()))
  for j in range(W):
    mi = min(mi, A[i][j] )
ans = 0
for i in range(H):
  for j in range(W):
    ans += A[i][j] - mi
print(ans)


  
