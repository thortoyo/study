S=input()
T=""
inv = 0
for i in range(len(S)):
  if S[i] == 'R':
    if inv==0: inv = 1
    else: inv = 0
  else:
    if inv == 1:
      if len(T) != 0 and S[i] == T[0]:
        T = T[1:]
      else:
        T=S[i]+T
    else:
      if  len(T) != 0 and S[i] == T[-1]:
        T = T[0:len(T)-1]
      else:
        T=T+S[i]
#  print(T)
pre = ""
ans = ""
if inv == 0:
  for i in range(len(T)):
    if pre != T[i]:
      ans += T[i]
else :
  for i in range(len(T)):
    if pre != T[len(T)-i-1]:
      ans += T[len(T)-i-1]
print(ans)
