import itertools

N=int(input())
m = [0] * 5
for i in range(N):
  S = input()
  if S[0] == 'M':
    m[0] += 1
  elif S[0] == 'A':
    m[1] += 1
  elif S[0] == 'R':
    m[2] += 1
  elif S[0] == 'C':
    m[3] += 1
  elif S[0] == 'H':
    m[4] += 1
ans = 0
for (a,b,c) in itertools.combinations([0,1,2,3,4], 3):
  ans += m[a] * m[b] * m[c]
print(ans)

