N=int(input())
f = 0
ans = "No"
for i in range(N):
  d1,d2=map(int,input().split())
  if d1==d2:
    f+=1
    if f == 3:
      ans = "Yes"
  else:
    f=0
print(ans)
