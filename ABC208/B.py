p=int(input())
c = [ 1 for _ in range(11)]
for i in range(2,11):
  c[i] = i*c[i-1]
ans = 0
for i in range(10,0,-1):
  while p >= c[i]:
    if p == 0: break
    p -= c[i]
    ans += 1
print(ans)
