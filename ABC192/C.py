N,K=map(int, input().split())
a = N
for i in range(K):
  sa = list(str(a))
  g1 = sorted(sa)
  g2 = sorted(sa,reverse=True)
#  print("--- ",i)
#  print(sa)
#  print(g1)
#  print(g2)
  g1 = "".join(g1)
  g2 = "".join(g2)
#  print(g1)
#  print(g2)
  a = int(g2) - int(g1)
print(a)

