n,a,b=map(int, input().split())
ans = 0
for i in range(n+1):
  d = i
  c = 0
  while d >0:
    c += (d%10)
    d = d // 10
#  print(i,c)
  if a <= c <= b:
    ans += i
print(ans)

