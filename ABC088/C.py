c = [ [0,0,0] for _ in range(3)]
for i in range(3):
  c[i] = list(map(int, input().split()))
for a0 in range(101):
  b0 = c[0][0] - a0
  b1 = c[0][1] - a0
  b2 = c[0][2] - a0
  if (((c[1][0]-b0) == (c[1][1]-b1) == (c[1][2]-b2)) and
      ((c[2][0]-b0) == (c[2][1]-b1) == (c[2][2]-b2))):
    print("Yes")
    break
else:
  print("No")

