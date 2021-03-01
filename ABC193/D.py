K=int(input())
S=input()
T=input()
sp = 0
tp = 0
scard = [ 0 for _ in range(10) ]
tcard = [ 0 for _ in range(10) ]
for i in range(4):
  scard[ int(S[i]) ] += 1;
  tcard[ int(T[i]) ] += 1;
for i in range(1,10):
  sp += i * pow(10, scard[i])
  tp += i * pow(10, tcard[i])
card = [ 0 for _ in range(10) ]
for i in range(1,10):
  card[i] = scard[i] + tcard[i];

win = 0
lose = 0
for sc in range(1,10):
  for tc in range(1,10):
    if card[sc] >= K: continue;
    if card[tc] >= K: continue;
    sp2 = sp + (sc * (pow(10,scard[sc]+1)-pow(10,scard[sc])))
    tp2 = tp + (tc * (pow(10,tcard[tc]+1)-pow(10,tcard[tc])))
    if sc == tc:
      m = (K-card[sc]) * (K-card[tc]-1)
    else:
      m = (K-card[sc]) * (K-card[tc])
    if sp2 > tp2:
      win += m
    else:
      lose += m
print(win/(win+lose))

