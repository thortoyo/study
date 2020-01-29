N,K=map(int,input().split())
H=list(map(int,input().split()))
H.sort(reverce=True)
ans = 0
if K < N:
  ans = sum(H[K:])
print(ans)


