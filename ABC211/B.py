a = 0
for i in range(4):
  s = input()
  if s == "H":
    a += 1
  elif s == "2B":
    a += 2
  elif s == "3B":
    a += 4
  else:
    a += 8
if a == 15:
  print("Yes")
else:
  print("No")

