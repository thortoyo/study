N=int(input())
a = 1
b = 1
aa = 3
bb = 5
f = 0
while aa < N:
  f = 0
  b = 1
  bb = 5
  while (bb + aa) <= N:
    if (bb + aa) == N:
      f = 1
      break
    b+=1
    bb*=5
  if f == 1:
    break
  a += 1
  aa *= 3
if f == 1:
  print(a,b)
else:
  print("-1")


