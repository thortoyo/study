N=int(input())
MT = []
for i in range(N):
  s,t = input().split()
  t = int(t)
  MT.append( [t, s] )
MT.sort(reverse=True)
print(MT[1][1])

