N = int(input())
ans = ""
while N > 0:
  N -= 1
  n = N % 26
  ans = chr(ord("a") + n) + ans
  N //= 26

print(ans)

