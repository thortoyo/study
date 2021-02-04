N=int(input())
A=list(map(int, input().split()))
B0 = [ [A[i], i] for i in range(2**N//2) ]
B1 = [ [A[i], i] for i in range(2**N//2,2**N) ]
B0.sort(reverse=True)
B1.sort(reverse=True)
if B0[0][0] > B1[0][0]:
  print(B1[0][1]+1)
else:
  print(B0[0][1]+1)
