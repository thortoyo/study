N=int(input())
A=list(map(int, input().split()))

def GCD(a,b):
  if b==0: return a
  else: return GCD( b, a%b )

g = 1
for i in range(N):
  lcm = g * A[i] // GCD(g,A[i])
  g = lcm
ans = 0
for i in range(N):
  ans += (g-1) % A[i]
print(ans)


