X,K,D = map(int, input().split())

x = abs(X)

ans = 0
if x >= K*D:
  ans = x - K*D
else:
  k = K - x//D
  if k%2==0:
    ans = x % D
  else:
    ans = D - (x % D)
print(ans)  

