N=int(input())
A0 = list(map(int, input().split()))
A1 = list(map(int, input().split()))
ans = 0
for i in range(N-1):
  A0[i+1] += A0[i]
for i in range(N-1,0,-1):
  A1[i-1] += A1[i]
for i in range(N):
  ans = max(ans, A0[i] + A1[i])
print(ans)

