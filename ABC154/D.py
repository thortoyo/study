N,K=map(int,input().split())
p=list(map(int,input().split()))
for i in range(N):
  p[i] = (p[i]+1)/2
C = [ 0 for _ in range(N+1) ]
C[0] = 0
for i in range(1,N+1):
  C[i] = p[i-1] + C[i-1]
ans = 0
for i in range(0,N-K+1):
  ans = max( C[i+K]-C[i], ans )
print(ans)

