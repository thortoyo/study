H=int(input())
i = 1
ans = 0
while H > 0:
  ans += i
  H = H // 2
  i *= 2

print(ans)

