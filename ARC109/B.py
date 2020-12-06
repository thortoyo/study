import math
n=int(input())
rn = math.sqrt(2*(n+1))
irn = int(rn)
for i in range(-3,4):
  if (n+1) <  (i+irn)*(i+irn+1)//2:
    print(n - (i+irn-1) + 1)
    break
