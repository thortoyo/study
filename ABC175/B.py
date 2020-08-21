N=int(input())
L=list(map(int, input().split()))
L.sort()
ans = 0
for i in range(N-2):
  for j in range(i+1, N-1):
    for k in range(j+1, N):
      if L[k] < (L[i] + L[j]):
        if L[i] == L[j] or L[j] == L[k]:
          continue
        ans += 1
print(ans)
  


