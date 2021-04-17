A,B=map(int, input().split())
ans = 1
for i in range(2,B//2+1):
  aa = (A-1) // i
  bb = B // i
#  print(aa,bb)
  if aa+1 < bb:
    ans = max(ans,i)
print(ans)
