N=int(input())
A = [ [0,i]  for i in range(N)]
B = [ [0,i]  for i in range(N)]
for i in range(N):
  A[i][0],B[i][0]=map(int, input().split())
A.sort()
B.sort()
if A[0][1] != B[0][1]:
  print(max(A[0][0],B[0][0]))
else:
  print(min(A[0][0]+B[0][0], min(max(A[0][0],B[1][0]),max(A[1][0],B[0][0]))))


