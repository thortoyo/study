N,K=map(int, input().split())
ans = 1
while N > 0:
  N //= K
  if N > 0: ans += 1
print(ans)

