import math
a,b,c=map(int,input().split())
#if ((a + b + (2 * math.sqrt(a*b))) < c):
#  print("Yes")
#else:
#  print("No")
if (((c-a-b) >= 0) and (4*a*b < ((c-a-b)*(c-a-b)) )):
  print("Yes")
else:
  print("No")


