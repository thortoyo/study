S=input()
K=int(input())

ss = []
for i in range( 1,K+1 ):
  for j in range( len(S)-i+1 ):
    ss.append(S[j:j+i])
ss.sort()
pre = '@'
for a in ss:
  if pre == a: continue
  pre = a
  K -= 1
#  print(a)
  if K==0:
    print(a)
    break
