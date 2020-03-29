A,B=map(int, input().split())
for i in range(1,10000):
  if ( A == int(i * 0.08) and B == int(i * 0.1) ):
    print(i)
    break
else:
  print(-1)
