N=int(input())
a=list(map(int, input().split()))
ans = 100000000
for i in range(N):
  d = 0
  while (a[i] %2 == 0):
    d += 1
    a[i] //= 2
  ans = min(d,ans)
print(ans)

