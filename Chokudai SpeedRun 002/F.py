N=int(input())
cnt=0
S={}
for i in range(N):
  A,B=map(int, input().split())
  if A>B:
    ss=str(A)+str(B)
  else:
    ss=str(B)+str(A)
  if ss not in S:
    S[ss] = 1;
    cnt += 1
print(cnt)
