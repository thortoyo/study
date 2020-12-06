n=int(input())
a=list(map(int, input().split()))
amax = 0
ans = 0
for k in range(2,1001):
  gcd = 0
  for i in range(n):
    if a[i]%k==0: gcd+=1
  if gcd > amax:
    ans = k
    amax = gcd
print(ans)
