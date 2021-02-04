s=input()
ans = 0
if "R" in s:
  ans = 1
if s[0] == s[1] == "R":
  ans += 1
if s[1] == s[2] == "R":
  ans += 1
print(ans)
