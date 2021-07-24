import math
N=int(input())
A = []
B = []
C = []
D = []
for i in range(N):
  a,b  = map(int, input().split())
  A.append(a)
  B.append(b)
for i in range(N):
  c,d  = map(int, input().split())
  C.append(c)
  D.append(d)
dx = C[0]-A[0]
dy = D[0]-B[0]
ng = 0
for i in range(1,N):
  C[i] -= dx
  D[i] -= dy
  if A[i]*A[i] + B[i]*B[i] != C[i]*C[i] + D[i]*D[i]:
    print("A", i, A[i],B[i],C[i],D[i])
    ng = 1
    break
  if i == 1:
    arc = math.atan2(B[i],A[i]) - math.atan2(C[i],D[i])
  else:
    if arc != math.atan2(B[i],A[i]) - math.atan2(C[i],D[i]):
      print("B")
      bg = 1
      break

if ng == 0:
  print("Yes")
else:
  print("No")

