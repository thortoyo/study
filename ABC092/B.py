N=int(input())
D,X=map(int, input().split())
ans = X
for i in range(N):
  a = int(input())
  ans += 1 + ((D-1)//a)
print(ans)
