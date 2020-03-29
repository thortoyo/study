S=input()
Q=int(input())
inv = 0
s0 = ""
s1 = ""
for i in range(Q):
  q = input()
  if q[0] == "1":
    if inv == 0: inv = 1
    else: inv = 0
  else:
    q,f,c = q.split()
    if f == "1":
      if inv == 0:
        s0 += c
      else:
        s1 += c
    else:
      if inv == 1:
        s0 += c
      else:
        s1 += c
if inv == 1:
  S = s1[::-1] + S[::-1] + s0
else:
  S = s0[::-1] + S + s1

print(S)


  