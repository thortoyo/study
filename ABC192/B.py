s=input()
ans = "Yes"
for i in range(len(s)):
  if i%2==0:
    if 'A' <= s[i] <= 'Z':
      ans = "No"
  else:
    if 'a' <= s[i] <= 'z':
      ans = "No"
print(ans)
