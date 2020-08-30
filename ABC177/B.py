S=input()
T=input()
ans = len(T)
for i in range(len(S)-len(T)+1):
  c = 0
  for j in range(len(T)):
    if T[j] != S[i+j]:
      c+=1
  ans = min(c,ans)
print(ans)

  