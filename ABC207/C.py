N=int(input())
R = []
L = []
for i in range(N):
  t,l,r  = map(int, input().split())
  l = l * 2
  r = r * 2
  if t==2:
    r -= 1
  elif t==3:
    l += 1
  elif t==4:
    r -= 1
    l += 1
  R.append(r)
  L.append(l)
ans = 0
for i in range(N-1):
  for j in range(i+1,N):
    if L[i] < L[j]:
      if L[j] <= R[i]: ans += 1
    else:
      if L[i] <= R[j]: ans += 1
print(ans)
