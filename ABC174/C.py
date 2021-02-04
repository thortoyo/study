K=int(input())
a = 0
m7 = 7%K
m10 = 10%K
if K % 2 == 0:
  print("-1")
else:
  for i in range(1000000):
    a = ((a%K) * m10 + m7) % K
    if a == 0:
      print(i+1)
      break
  else:
    print("-1")

