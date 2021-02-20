B,C=map(int,input().split())
a0 = B+(C-2)//2
a1 = B-C//2
a2 = -B+(C-1)//2
a3 = -B-(C-1)//2
#print(a0,a1,a2,a3)
ans = 0
if C == 1:
  if B==0: ans = 1
  else: ans = 2
elif B > 0:
  ans = a0-a1+1 + a2-a3+1
  if a1 <= a2:
    ans -= a2-a1+1
else:
  ans = a0-a1+1 + a2-a3+1
  if a0 >= a3:
    ans -= a0-a3+1
print(ans)

