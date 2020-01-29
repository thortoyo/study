import itertools
N = int(input())
P = list(map(int, input().split()))
Q = list(map(int, input().split()))
i = 1
Nin = [ i for i in range(1,N+1)]
for li in itertools.permutations( Nin ):
  li = list(li)
  if li == P:
    pnum = i
  if li == Q:
    qnum = i
  i += 1
print(abs(pnum-qnum) )

