X=int(input())
m = 100
for i in range(5000):
  if m >= X:
    print(i)
    break
  m += (m // 100)

