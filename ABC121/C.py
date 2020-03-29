N,M=map(int, input().split())
AB=[ [] for _ in range(N)]
for i in range(N):
  AB[i] = list( map(int, input().split()))
AB.sort()
#print(AB)
cnt = ans = 0
for i in range(N):
  buy = AB[i][1]
  if cnt + AB[i][1] >= M:
    buy = M - cnt
  cnt += buy
  ans += buy * AB[i][0]
#  print(buy,cnt,ans)
  if cnt >= M:
    break
print(ans)

