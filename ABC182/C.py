import itertools
na=list(map(int,list(input())))
nsum = sum(na)
if nsum%3==0:
  print("0")
else:
  re = nsum%3
#  print(nsum, re)
  ok = 0
  for i in range(1, len(na)):
    for v in itertools.permutations(na, i):
#      print(" ",i,v)
      if sum(v)%3 == re:
        print(i)
        ok = 1
        break
    if ok==1: break
  else:
    print("-1")

  