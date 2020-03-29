N=int(input())
S = ""
while N != 0:
  if N%2==0:
    S = "0" + S
  else:
    S = "1" + S
    N -= 1
  N /= -2
if S == "": S = "0"
print(S)

