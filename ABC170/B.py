X,Y=map(int, input().split())
ok = 0
for i in range(101):
  for j in range(101):
    if (i+j == X) and ((i*2)+(4*j)==Y):
      ok = 1
      break
  if ok == 1:
    break
if ok == 1:
  print("Yes")
else:
  print("No")
