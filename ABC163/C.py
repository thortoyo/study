N=int(input())
A=list(map(int, input().split()))
s = [0] * N
for i in range(N-1):
  s[ A[i]-1 ]+=1
for i in range(N):
  print(s[i])



