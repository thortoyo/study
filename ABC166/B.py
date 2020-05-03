N,K=map(int,input().split())
ok = [0 for i in range(N)] 
for i in range(K):
  d = int(input())
  A = list(map(int, input().split()))
  for a in A:
    ok[a-1]+=1
ans = 0
for i in range(N):
  if ok[i] == 0:
    ans += 1
print(ans)
