N=int(input())
A=list(map(int, input().split()))
AN = []
for i in range(N):
  AN.append([A[i], i+1])
AN.sort()
print(AN[N-2][1])

