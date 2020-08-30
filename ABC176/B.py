N=list(input())
t = 0
for a in N:
  t += int(a)
if t%9 == 0:
  print("Yes")
else:
  print("No")
  