s=input()
flg = 0
ans = 0
for i in range(len(s)):
  if s[i] == 'Z':
    flg=1
  elif flg == 1 and s[i] == 'O':
    flg+=1
  elif flg == 2 and s[i] == 'N':
    flg+=1
  elif flg == 3 and s[i] == 'e':
    flg=0
    ans+=1
  else:
    flg = 0
print(ans)


