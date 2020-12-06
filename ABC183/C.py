import itertools
N,K=map(int,input().split())
T = [ [] for _ in range(N) ]
for i in range(N):
  T[i]=list(map(int,input().split()))
ans = 0
for to in itertools.permutations(range(1,N)):
  l = 0
  pre = 0
  for i in range(N-1):
    l += T[pre][to[i]]
    pre = to[i]
  l += T[pre][0]
  if l==K:
    ans+=1
print(ans)

