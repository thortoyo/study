A,B,C=map(int, input().split())
k = 0
if A == B and A != C:
  k = 1
if A == C and A != B:
  k = 1
if B == C and A != B:
  k = 1
if k == 1:
  print("Yes")
else:
  print("No")

