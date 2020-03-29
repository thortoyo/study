N=int(input())
A=list(map(int,input().split()))
A.sort()
for i in range(1,N):
  if A[i] == A[i-1]:
    print("NO")
    break;
else:
  print("YES")

