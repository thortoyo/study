a,b,x,y=map(int,input().split())
if a > b:
  ans = min(x + (a-b-1)*y, x + (a-b-1)*2*x)
else:
  ans = min(x +(b-a)*y, x + (b-a)*2*x)

print(ans)


