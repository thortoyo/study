N=int(input())
S = ""
for i in range(120):
  if N%2==1:
    S = "A" + S
    N -= 1
  else:
    S = "B" + S
    N //= 2
  if N == 0:
    break
#  print(N)
print(S)

#a = 0
#for s in S:
#  if s == "A":
#    a += 1
#  else:
#    a *= 2
#  print(a)
#print(a)
  
  
