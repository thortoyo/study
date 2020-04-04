N=int(input())
A=[0] + list(map(int, input().split())) + [0]
dist = 0
for i in range(1,N+2):
  dist += abs(A[i]-A[i-1])

for i in range(1,N+1):
  if (A[i-1] <= A[i] <= A[i+1]) or (A[i-1] >= A[i] >= A[i+1]):
    print(dist)
  else:
    print(dist - 2 * min( abs(A[i]-A[i-1]), abs(A[i]-A[i+1]) ) )

