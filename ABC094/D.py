n=int(input())
A=list(map(int,input().split()))
ma = max(A)
mid = ma / 2
l = 10000000000
f = 0
for i in range(n):
  if ((ma == A[i]) and (f==0)):
    f = 1
    continue
  if abs(l) > abs(A[i]-mid):
    l = A[i]-mid
print(ma, int(mid+l))
