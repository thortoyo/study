S=input()
sn = len(S)
for i in range(len(S)):
  if S[sn-i-1] != '0': break
  S = S[0:sn-i-1]
ans = 1
for i in range(len(S)//2):
  if S[i] != S[len(S)-i-1]:
    ans = 0
    break
if ans == 1:
  print("Yes")
else:
  print("No")

