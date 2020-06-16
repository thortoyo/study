X,N=map(int,input().split())
p=list(map(int,input().split()))
p.sort()
if X in p:
  for i in range(1,100):
    if not X-i in p:
      print(X-i)
      break
    if not X+i in p:
      print(X+i)
      break
else:
  print(X)

