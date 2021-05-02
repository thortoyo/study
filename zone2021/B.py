N,D,H=map(int,input().split())
ans = 0.0
for i in range(N):
  d,h=map(int,input().split())
  h0 = H - ((H-h) /(D-d) * D)
  ans = max(ans, h0)
print(ans)
