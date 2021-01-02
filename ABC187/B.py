N=int(input())
x=[ 0 for _ in range(N)] 
y=[ 0 for _ in range(N)] 
for i in range(N):
  x[i],y[i] = map(int, input().split())
ans = 0
for i in range(N-1):
  for j in range(i+1,N):
    if ( abs(x[j] - x[i]) >= abs(y[j] - y[i])):
      ans +=1
print(ans)

