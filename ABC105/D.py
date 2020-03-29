# 累積和の中で %M が同じものが、差分が M の倍数になるもの

N,M=map(int,input().split())
A=list(map(int,input().split()))

C = [ 0 for _ in range(N) ]
C[0] = A[0] % M
d = { 0:1 }
if C[0] in d:
  d[C[0]] += 1
else:
  d[C[0]] = 1

ans = 0
for i in range(1,N):
  C[i] = (C[i-1] + A[i]) % M
  if C[i] in d:
    d[C[i]] += 1
  else:
    d[C[i]] = 1

for dv in d.values():
  if dv > 1:
    ans += dv * (dv-1) // 2
print(ans)
