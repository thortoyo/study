N = int(input())
s = []
for i in range(N):
  s.append(input())
ans = ""
ng = 0
for i in range(N//2):
  for j in range(N):
    if s[i][j] in s[N-i-1]:
      ans += s[i][j]
      break
  else:
    ng = 1
    break
if ng == 1:
  print("-1")
else:
  if N%2==1:
    ans += s[N//2][0]
  for i in range(N//2):
    ans += ans[N//2-i-1]
  print(ans)
