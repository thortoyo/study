S = input()
T = input()
for i in range(len(S)):
  if S == T:
    print("Yes")
    break
  S = S[1:] + S[0]
else:
  print("No")
  

