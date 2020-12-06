dx = [0,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1, 0, 1, 2,-2,-1, 0, 1, 2, 0,3,-3]
dy = [3, 2, 2,2,2,2, 1, 1,1,1,1, 0, 0,0,0,0,-1,-1,-1,-1,-1,-2,-2,-2,-2,-2,-3,0,0]

def chk1a(a,b,c,d):
  if a+b == c+d:
    return 1
  if a-b == c-d:
    return 1
  return 0

def chk1(a,b,c,d):
  if chk1a(a,b,c,d) == 1:
    return 1
  for i in range(len(dx)):
    if (a+dx[i] == c) and (b+dy[i] == d):
      return 1
  return 0

a,b=map(int,input().split())
c,d=map(int,input().split())
ans = 3
if a==c and b==d:
  ans = 0
elif chk1(a,b,c,d) == 1:
  ans = 1
else:
  if (a+b)%2 == (c+d)%2:
    ans = 2
  else:
    for i in range(len(dx)):
      if chk1(a+dx[i], b+dy[i], c, d) == 1:
        ans = 2
        break
      if chk1(c+dx[i], d+dy[i], a, b) == 1:
        ans = 2
        break
print(ans)


