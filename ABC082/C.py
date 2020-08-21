N=int(input())
A=list(map(int,input().split()))
m={}
for i in range(N):
  if A[i] in m:
    m[A[i]] += 1
  else:
    m[A[i]] = 1
ans = 0
for k,n in m.items():
  if k <= n:
    ans += n-k
  else:
    ans += n
print(ans)

