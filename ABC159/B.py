S=input()
n= len(S)
ng = 0
s = 0
e = n
for i in range((e-s)//2):
  if S[s+i] != S[e-i-1]:
    ng = 1
nn = (n-1)//2
for i in range(nn//2):
  if S[i] != S[nn-i-1]:
    ng = 1
nn = (n+3)//2 - 1
for i in range((n-nn)//2):
  if S[nn+i] != S[n-i-1]:
    ng = 1
if ng == 1:
  print("No")
else:
  print("Yes")
