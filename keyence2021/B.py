N,K = map(int,input().split())
A=list(map(int, input().split()))
b = []
c = [ 0 for _ in range(N+3)]
for i in range(N):
  c[A[i]] += 1
nowmin = c[0]
#print(c)
for i in range(1,N+2):
  if ( nowmin > c[i] ):
    for j in range(nowmin-c[i]):
      b.append(i)
    nowmin = c[i]
b.sort(reverse=True)
#print(b)
print(sum(b[0:K]))

