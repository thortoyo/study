N=int(input())
A = list(map(int,input().split()))
A2 = [ A[i]*2 for i in range(N) ]
asum = sum(A2)
tgt = asum//2
tmpa = 0
ans = 0
for i in range(N):
  tmpa += A2[i]
  if tmpa >= tgt:
    if i == 0:
      ans = tmpa - tgt
    else:
      ans = min(tmpa-tgt, tgt-(tmpa-A2[i]))
#      print(tgt, tmpa,A2[i],ans)
    break
print(ans)
