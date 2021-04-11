import math

R,X,Y=map(int, input().split())
dis = math.sqrt( X*X + Y*Y )
if dis < R:
  ans = 2
else:
  ans = dis // R
  if dis % R != 0:
    ans += 1
print(int(ans))
