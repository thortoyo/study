X,Y,Z=map(int, input().split())
ans = Y*Z//X
if (Y*Z)%X == 0:
  print(ans-1)
else:
  print(ans)
