A = [0 for _ in range(9)]
A[0],A[1],A[2] = map(int,input().split())
A[3],A[4],A[5] = map(int,input().split())
A[6],A[7],A[8] = map(int,input().split())
N = int(input())
b = []
h = [ 0 for _ in range(9) ]
for i in range(N):
  b = int(input())
  for j in range(9):
    if A[j] == b:
      h[j] = 1
ans = 0
for i in range(3):
  if h[i*3] == h[i*3+1] == h[i*3+2] == 1:
    ans = 1
    break
  if h[i] == h[3+i] == h[6+i] == 1:
    ans = 1
    break
if h[0] == h[4] == h[8] == 1:
    ans = 1
if h[2] == h[4] == h[6] == 1:
    ans = 1
if ans == 0:
  print("No")
else:
  print("Yes")


