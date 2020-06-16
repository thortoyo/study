N=int(input())
NN = N
i = 2
ans = 0
while i*i <= NN:
  if N%i==0:
    j = 0
    while N%i==0:
      N /= i
      j+=1
    k = 1
    while j>0:
      if j - k < 0: break
      ans += 1
#      print(i,ans,j,k)
      j -= k
      k += 1
  i += 1
if N != 1:
  ans += 1
print(ans)


