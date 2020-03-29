N=int(input())

a = 2
prime = [ 1 ] * 55559
prime[0] = 0
prime[1] = 0
while a < 55556:
  if prime[a] == 1:
    b = a + a
    while b < 55556:
      prime[b] = 0
      b += a
  a += 1
d = []
n = 0
for i in range(55556):
  if prime[i] == 1:
    if i%5==1:
      d.append(i)
      n += 1
      if n == N:
        break
      
for i in d:
  print(str(i)+" ", end="")
print("")
