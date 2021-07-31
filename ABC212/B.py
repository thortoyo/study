def addd(a):
  if a == 9:
    return 0;
  else:
    return a+1

x=input()
ng = 0
if x[0] == x[1] == x[2] == x[3]:
  ng = 1
else:
  ng = 1
  for i in range(1,4):
    if int(x[i]) != addd(int(x[i-1])):
      ng = 0
if ng == 0:
  print("Strong")
else:
  print("Weak")
  
