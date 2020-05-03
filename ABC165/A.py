K=int(input())
A,B=map(int,input().split())
ok = 0
for i in range(A,B+1):
  if ( i%K==0 ):
    ok = 1
if(ok==1):
  print("OK")
else:
  print("NG")
