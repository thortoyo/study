N=int(input())
ans = 112345678901;
for i in range(N):
  A,P,X=map(int,input().split())
  if X > A:
    ans = min(ans, P)
if ans == 112345678901:
  print(-1)
else:
  print(ans)

