N=int(input())
a = 1
for i in range(60):
  a *= 2
  if a > N:
    print(i)
    break

