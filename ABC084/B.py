A,B=map(int, input().split())
s=input()

ng = 0
if not (s[0:A].isdecimal()):
  ng = 1
if s[A] != "-": ng = 1
if not (s[A+1:A+B+1].isdecimal()):
  ng = 1
if ng == 1:
  print("No")
else:
  print("Yes")
  
