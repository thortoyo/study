import itertools
N=int(input())
A = list(map(int, input().split()))
AA = [ A[i] for i in range(N)]
ans = 0
for i in range(N):
  ans += A[i] * A[i]
ans *= (N-1)

for i in range(N-2,0,-1):
  AA[i] = AA[i+1] + A[i]
for i in range(N-1):
  ans -= 2 * A[i] * AA[i+1]
print(ans)


