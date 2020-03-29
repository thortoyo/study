A,B,C,X,Y=map(int, input().split())
ans = 50000000000
for i in range( max(X,Y)+1 ):
  ans = min(ans, C*i*2 + A*(max(0,(X-i)))+B*(max(0,(Y-i))))
print(ans)
