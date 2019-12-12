a=int(input())
m={}
for i in range(1000000):
  if a in m:
    print(i+1)
    break
  m[a] = i
  if a %2==0:
    a //=2
  else:
    a = 3*a+1

