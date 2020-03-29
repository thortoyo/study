N = int(input())
A = list(map(int, input().split()))
f = 1
for i in range(N):
  if A[i] % 2 == 0:
    if (A[i] % 3 != 0) and (A[i] % 5 != 0):
      f = 0
if f == 0:
  print("DENIED")
else:
  print("APPROVED")

