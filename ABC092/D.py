A,B=map(int, input().split())

# 100 x 100 ŒÅ’è
print("100 100")

A -= 1
B -= 1
for y in range(50):
  s = ""
  if y%2 == 1:
    for x in range(100):
      if A > 0 and x%2 == 0:
        s += "."
        A -= 1
      else:
        s += "#"
    print(s)
  else:
    print("#" * 100)
for y in range(50):
  s = ""
  if y%2 == 1:
    for x in range(100):
      if B > 0 and x%2 == 0:
        s += "#"
        B -= 1
      else:
        s += "."
    print(s)
  else:
    print("." * 100)
