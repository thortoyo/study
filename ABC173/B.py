N=int(input())
a = 0
w = 0
t = 0
r = 0
for i in range(N):
  S=input();
  if S[0] == "A":
    a+=1
  elif S[0] == "W":
    w+=1
  elif S[0] == "T":
    t+=1
  else:
    r+=1
print("AC x",a)
print("WA x",w)
print("TLE x",t)
print("RE x",r)

