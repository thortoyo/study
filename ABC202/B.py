s=input()
ls = len(s)
ans = [ "0" for _ in range(ls)]
for i in range(ls):
  if s[i] == "0" or s[i] == "1" or s[i] == "8":
    ans[ls-i-1] = s[i]
  elif s[i] == "6":
    ans[ls-i-1] = "9"
  else:
    ans[ls-i-1] = "6"
print("".join(ans))

