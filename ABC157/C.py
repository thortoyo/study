N,M = map(int,input().split())
k = [-1 for i in range(N)]
ng = 0
for i in range(M):
  s,c = map(int,input().split())
  if k[s-1] == -1:
    k[s-1] = c
  elif k[s-1] != c:
    ng = 1
    break
if k[0] == 0:
  if N != 1:
    ng = 1
if ng==1:
  print("-1")
else:
  if k[0] == -1:
    if N == 1:
      k[0] = 0
    else:
      k[0] = 1
  for i in range(N):
    if k[i] == -1:
      k[i] = 0
  print("".join(map(str,k)))

