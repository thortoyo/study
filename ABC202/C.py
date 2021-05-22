N=int(input())
A=list(map(int, input().split()))
B=list(map(int, input().split()))
C=list(map(int, input().split()))
nt = [0 for _ in range(N)]
cn = [0 for _ in range(N)]
for i in range(N):
  cn[ C[i]-1 ]+=1
for i in range(N):
  nt[ B[i]-1 ]+=cn[i]
ans = 0
for i in range(N):
  ans+= nt[A[i]-1]
print(ans)
