N=int(input())
A=list(map(int, input().split()))
d = dict()
ans = 0
for i in range(N):
  if A[i] in d:
    ans += i - d[ A[i] ]
    d[A[i]] += 1
  else:
    ans += i
    d[A[i]] = 1
print(ans)
