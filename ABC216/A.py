x,y=map(int,input().split("."))
if 0 <= y <= 2:
  s = "-"
elif 3 <= y <= 6:
  s = ""
else:
  s = "+"
print(x,s,sep="")

