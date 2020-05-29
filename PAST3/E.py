N,M,Q = map(int, input().split())
to = [ [] for i in range(N+1)]
for i in range(M):
  u,v = map(int, input().split())
  u -= 1; v -= 1
  to[u].append(v)
  to[v].append(u)

c = list(map(int, input().split()))

for i in range(Q):
  s = list(map(int, input().split()))
  s[1] -= 1
  if s[0] == 1:
    print(c[s[1]])
    for v in to[s[1]]:
      c[v] = c[s[1]]
  else:
    print(c[s[1]])
    c[s[1]] = s[2]
