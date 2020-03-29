# BFS
from collections import deque

N=int(input())

dp = [-1] * 200005;
q = deque()

g = [1]
a = 6
while a <= 100000:
  g.append(a)
  a *= 6
a = 9
while a <= 100000:
  g.append(a)
  a *= 9
g.sort(reverse=True)

dp[0] = 0
q.append(0)

while len(q) > 0:
  v = q.popleft()
  if v == N: break
  for j in g:
    if dp[v+j] != -1: continue
    if v+j > N: continue
    dp[v+j] = dp[v] + 1
    q.append(v+j)

print(dp[N])
