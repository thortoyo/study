def gcd(a,b):
  if b == 0:
    ret = a
  else:
    ret = gcd(b, a%b)
  return ret

N = int(input())
A = list(map(int, input().split()))
A.sort(reverse=True)
gu = [0 for i in range(N)]
gl = [0 for i in range(N)]
if N == 2:
  if A[0] > A[1]:
    print(A[0])
  else:
    print(A[1])
else:
  max = 0
  gu[0] = A[0]
  for i in range(1,N-1):
    y = gu[i-1]
    x = A[i]
    gu[i] = gcd(y,x)
    
  gl[0] = A[N-1]
  for i in range(1,N-1):
    y = gl[i-1]
    x = A[N-1-i]
    gl[i] = gcd(y,x)

  for i in range(N):
    if i == 0:
      x = gl[N-2]
    elif i == N-1:
      x = gu[N-2]
    else:
      y = gu[i-1]
      x = gl[N-2-i]
      x = gcd(y,x)
    if max < x:
      max = x
  print(max)
