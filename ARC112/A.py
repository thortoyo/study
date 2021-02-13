T=int(input())
for i in range(T):
  L,R=map(int, input().split())
  if R-L < L:
    print("0")
  else:
    m = R-L-L+1
    print( m*(m+1)//2 )
