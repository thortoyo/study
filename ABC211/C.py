S=input()
a = [0] * 8
mod = 1000000007
for i in range(len(S)):
  if S[i] == 'c':
    a[0] += 1
  elif  S[i] == 'h':
    a[1] += a[0]
    a[1] %= mod
  elif  S[i] == 'o':
    a[2] += a[1]
    a[2] %= mod
  elif  S[i] == 'k':
    a[3] += a[2]
    a[3] %= mod
  elif  S[i] == 'u':
    a[4] += a[3]
    a[4] %= mod
  elif  S[i] == 'd':
    a[5] += a[4]
    a[5] %= mod
  elif  S[i] == 'a':
    a[6] += a[5]
    a[6] %= mod
  elif  S[i] == 'i':
    a[7] += a[6]
    a[7] %= mod
print(a[7])


