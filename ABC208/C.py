N,K=map(int, input().split())
a = list(map(int, input().split()))
aa = []
for i in range(N):
  aa.append([a[i],i])
aa.sort()
base = K // N
ans = [ 0 for _ in range(N) ]
for i in range(N):
  ans[aa[i][1]] = base + (1 if K%N > i else 0)
for i in range(N):
  print(ans[i])



