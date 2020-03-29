N=int(input())
A=list(map(int, input().split()))
ans = 1000000000
for x in range(1,101):
  total = 0
  for i in range(N):
    total += (A[i]-x)*(A[i]-x)
  ans = min( ans, total ) 
print(ans)

