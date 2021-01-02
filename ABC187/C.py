N=int(input())
d = {}
for i in range(N):
  s=input()
  k = s
  ad = 1
  if s[0] == '!':
    k = s[1:]
    ad = 2
  if k not in d:
    d[k] = ad
  else:
    d[k] |= ad
for kk in d:
  if d[kk] == 3:
    print(kk)
    break
else:
  print("satisfiable")

