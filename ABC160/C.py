N,X,Y=map(int,input().split())
D = [ 1 in range(N-1)]
for i in range(N-Y+1):
  D[X+i+1] += 1
for i in range((Y-X)//2):
  D[X-i-1] += 1
for k in range(1,N):
  ans = 0
  for j in range(N-1):
    if ( j >= k ):
      ans += 1
  print(ans)
