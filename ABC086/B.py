a,b=input().split()
a = int(a+b)
hei = 0
for i in range(1000):
  if i*i == a:
    hei = 1
if hei == 1:
  print("Yes")
else:
  print("No")
