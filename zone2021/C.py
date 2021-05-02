def chk(a,b,c):
  maxn = [0 for _ in range(5) ]
  for i in range(5):
    maxn[i] = max(maxn[i], a[i])
    maxn[i] = max(maxn[i], b[i])
    maxn[i] = max(maxn[i], c[i])
  minn = 1000000000
  for i in range(5):
    minn = min(minn, maxn[i])
  return minn

N=int(input())
tgt0 = list(map(int, input().split()))
tgt1 = list(map(int, input().split()))
tgt2 = list(map(int, input().split()))
ans = chk(tgt0, tgt1, tgt2)
for i in range(N-3):
  a = list(map(int, input().split()))
  a0 = chk(a, tgt1, tgt2)
  a1 = chk(tgt0, a, tgt2)
  a2 = chk(tgt0, tgt1, a)
  if a0 > a1 and a0 > a2:
    if a0 > ans:
      for j in range(5): tgt0[j] = a[j]
      ans = a0
  if a1 > a0 and a1 > a2:
    if a1 > ans:
      for j in range(5): tgt1[j] = a[j]
      ans = a1
  if a2 > a1 and a2 > a0:
    if a2 > ans:
      for j in range(5): tgt2[j] = a[j]
      ans = a2
  print(ans)
  print("   ",tgt0)
  print("   ",tgt1)
  print("   ",tgt2)
print(ans)


