N,M,Q = map(int, input().split())
n = [ [] for _ in range(N+1) ]
m = [N] * (M+1)
for i in range(Q):
  s = list(map(int, input().split()))
  if s[0] == 1:
    ans = 0
    for mv in n[s[1]]:
      ans += m[mv]
    print(ans)
  else:
    n[s[1]].append(s[2])
    m[s[2]] -= 1
