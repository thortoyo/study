A,B,K=map(int, input().split())
if K > A:
  K -= A
  A = 0
else:
  A -= K
  K = 0
if K > B:
  B = 0
else:
  B -= K
print(A,B)

