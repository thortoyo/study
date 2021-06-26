a,b,c,d=map(int, input().split())
if c * d - b <= 0:
  print("-1")
else:
  if (a % (c * d - b)) == 0:
    print( a // (c * d - b) )
  else:
    print( a // (c * d - b) + 1) 
