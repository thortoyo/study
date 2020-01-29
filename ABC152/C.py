N=int(input())
A = list(map(int,input().split()))
amin = N+1
ans = 0
for i in range(N):
  if amin > A[i]:
    ans += 1
    amin = A[i]
print(ans)

