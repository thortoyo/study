s=input()
x,y=map(int, input().split())
cx=[]
cy=[]
dirx=1
l=0
ini=1
for i in range(len(s)):
  if s[i] == "F":
    l += 1
  else:
    if ini:
      x -= l
      ini = 0
    else:
      if dirx:
        cx.append(l)
      else:
        cy.append(l)
    l = 0
    dirx = not dirx

if ini == 0:
  if dirx:
    cx.append(l)
  else:
    cy.append(l)
else:
  x -= l

#print(cx)
#print(cy)


ng = 0
dp = {0}
for i in range( len(cx) ):
  dpn = set()
  for d in dp:
    dpn.add(d+cx[i])
    dpn.add(d-cx[i])
#  print(dpn)
  dpn, dp = dp, dpn
  
if not x in dp:
  ng = 1
#  print("x", x)
  
dp = {0}
for i in range( len(cy) ):
  dpn = set()
  for d in dp:
    dpn.add(d+cy[i])
    dpn.add(d-cy[i])
#  print(dpn)
  dpn, dp = dp, dpn
  
if not y in dp:
  ng = 1
#  print("y", y)

if ng==0:
  print("Yes")
else:
  print("No")
  
