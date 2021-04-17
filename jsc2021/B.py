N,M=map(int, input().split())
AB = [ 0 for _ in range(1001)]
A = list(map(int, input().split()))
B = list(map(int, input().split()))
for i in range(N):
  AB[ A[i] ] += 1
for i in range(M):
  AB[ B[i] ] += 1
for i in range(1001):
  if AB[i] == 1:
    print(i, end=" ")
