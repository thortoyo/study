H,W,N=map(int, input().split())
card = []
for i in range(N):
  C = list(map(int, input().split()))
  C.append(i)
  card.append(C)
card.sort()
dif = 0
pre = 0
for i in range(N):
  if card[i][0] != pre:
    dif += card[i][0] - pre - 1
  pre = card[i][0]
  card[i][0] -= dif

card.sort(key=lambda x: x[1])
dif = 0
pre = 0
for i in range(N):
  if card[i][1] != pre:
    dif += card[i][1] - pre - 1
  pre = card[i][1]
  card[i][1] -= dif
card.sort(key=lambda x: x[2])
for i in range(N):
  print(card[i][0],card[i][1])

