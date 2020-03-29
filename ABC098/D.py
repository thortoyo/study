N=int(input())
A=list(map(int, input().split()))
ans = 1
r = 1
AA = A[0]
for i in range(1,N):
#  print( AA & A[i], AA ,A[i], end="")
  r+=1
  if ( AA & A[i] == 0 ):
    AA |= A[i]
  else:
    for l in range(i-r+1,i):
      r -= 1
      AA ^= A[l]
#      print( " - ", AA & A[i], AA ,A[i],A[l], end="")
      if ( AA & A[i] == 0 ):
        break
    AA |= A[i]
  ans += r
#  print( " -- ", r,ans )
print(ans)
