N=int(input())
S=input()
cnt = 0
for i in range(1,N):
  if S[i] == 'E': cnt += 1
ans = cnt
for i in range(1,N):
  if S[i-1] == 'W': cnt += 1
  if S[i] == 'E': cnt -= 1
  ans = min(ans, cnt)
print(ans)
