N = int(input())
d = {}
dmax = 1
for i in range(N):
  s = input()
  if s in d:
    d[s] += 1
    if dmax < d[s]:
      dmax = d[s]
  else:
    d[s] = 1

dd = []
for k,v in d.items():
  if v == dmax:
    dd.append(k)

dd.sort()
for dv in dd:
  print(dv)

