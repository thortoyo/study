N=int(input())
S = []
for i in range(N):
  S.append((input().split()))
S.sort()
flg = 0;
for i in range(N-1):
  if S[i] == S[i+1]: flg = 1

if flg == 1:
  print("Yes")
else:
  print("No")


