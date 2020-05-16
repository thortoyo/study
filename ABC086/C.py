N=int(input())
t0=0
x0=0
y0=0
for i in range(N):
  t,x,y = map(int, input().split())
  l = abs(x-x0) + abs(y-y0)
  if (l > (t-t0)) or (l%2 != (t-t0)%2):
    print("No")
    break
  else:
    x0 = x
    y0 = y
    t0 = t
else:
  print("Yes")
