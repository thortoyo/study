N,Y=map(int,input().split())
ok = 0
for i in range(N+1):
  for j in range(N+1-i):
    k = N - i - j
    if i*10000+j*5000+k*1000 == Y:
      print(i,j,k)
      ok = 1
      break
  if ok == 1:
    break
if ok == 0:
  print("-1 -1 -1")

