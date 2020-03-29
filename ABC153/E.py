H,N=map(int,input().split())
sa = 1
sb = 1000000
for i in range(N):
  a,b=map(int,input().split())
  if (sa / sb) < (a/b):
    
i = 1
ans = 0
while H > 0:
  ans += i
  H = H // 2
  i *= 2

print(ans)

