def GCD(a,b):
    if a % b == 0:
        return b
    return GCD( b, a%b )

ans = 0
K=int(input())
for i in range(1,K+1):
  for j in range(1,K+1):
    for k in range(1,K+1):
      ans +=  GCD(k, GCD(i,j) )
print(ans)

