N=int(input())
A=list(map(int, input().split()))
B=list(map(int, input().split()))
amax=0
bmin=10000
for i in range(N):
  amax = max(A[i],amax)
  bmin = min(B[i],bmin)
if amax > bmin:
  print(0)
else:
  print(bmin-amax+1)

