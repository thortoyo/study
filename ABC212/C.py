N,M=map(int, input().split())
A=list(map(int, input().split()))
B=list(map(int, input().split()))
A.sort()
B.sort()
ans = 1000000001
for i in range(N):
  l = 0
  r = M
  while( l+1 < r ):
    m = (l+r)//2
    if B[m] < A[i]:
      l = m
    else:
      r = m
  ans = min(ans, abs(A[i]-B[l]))
  if l+1 < M:
    ans = min(ans, abs(A[i]-B[l+1]))
print(ans)



