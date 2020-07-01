N,M,K=map(int, input().split())
A = [0]
B = [0]
A += list(map(int, input().split()))
B += list(map(int, input().split()))
for i in range(N):
  A[i+1] += A[i]
for i in range(M):
  B[i+1] += B[i]
j = 0
ans = 0
for i in range(N,-1,-1):
  while (j <= M) and (A[i] + B[j] <= K):
    ans = max(ans, i+j)
#    print(i,j,A[i],B[j], A[i] + B[j], ans)
    j += 1
print(ans)

