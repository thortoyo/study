from collections import deque
N=int(input())
A = list(map(int, input().split()))
A.sort(reverse=True)
q = deque([A[0]])
ans = 0
for i in range(1,N):
  ans += q.popleft()
  q.append( A[i] )
  q.append( A[i] )
print(ans)
