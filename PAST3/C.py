A,R,N= map(int, input().split())
n = A
if R == 1:
  N = 1
while N > 1:
  n *= R
  if n > 1000000000:
    break
  N -= 1
if N == 1:
  print(n)
else:
  print("large")

