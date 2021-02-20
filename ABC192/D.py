X=input()
M=int(input())
xmax = 0
for i in range(len(X)):
  xmax = max(xmax, int(X[i]))
l = xmax
r = M+1
while l+1<r:
  m = (l+r)//2
  num = 0
  base = 1
  for i in range(len(X)):
    num += int(X[len(X)-i-1]) * base;
    base *= m
#    print(m,num,base)
  if M >= num:
    l = m
  else:
    r = m
print(l-xmax)
