N=int(input())
h=[0] + list(map(int,input().split()))

ans=0
for i in range(N):
  if h[i+1] > h[i]:
    ans+=h[i+1]-h[i]
print(ans)

