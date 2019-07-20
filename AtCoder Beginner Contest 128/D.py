N,K=map(int,input().split())
V=list(map(int,input().split()))
total = 0
if N<=K:
  for i in range(N):
    if V[i] > 0:
      total += V[i]
  print(total)
else:
  max = 0
  for L in range(K+1):
    for R in range(K-L+1):
#      print(L,R)
      p = K-L-R
      V0 = []
      if L>0:
        V0 = V0 + V[0:L]
#        print(V[0:L])
      if R>0:
        V0 = V0 + V[N-R:N]
#        print(V[N-R:N])
      V0.sort()
#      print(V0)
      for ii in range(len(V0)):
        if p <= 0:
            break
        if V0[ii] < 0:
          V0[ii] = 0
          p -= 1
        else:
          break
#      print(V0)
      su = sum(V0)
#      print(su)
      if max < su:
        max = su
  print(max)  
          
