N=int(input())
S=list(input())
Q=int(input())
inv = 0
for i in range(Q):
  t,a,b=map(int, input().split())
  if t == 1:
    a -= 1
    b -= 1
    if inv==0:
      ss = S[a]
      S[a] = S[b]
      S[b] = ss
    else:
      if a >= N:  a -= N
      else:       a += N
      if b >= N:  b -= N
      else:       b += N
      ss = S[a]
      S[a] = S[b]
      S[b] = ss
  else:
    if inv == 0: inv = 1
    else:  inv = 0
if inv==1:
  SS = S[N:2*N] + S[0:N]
else:
  SS=S
print("".join(SS))

