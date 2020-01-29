ns = input()
N=int(ns)

C = [[ 0 for _ in range(10)] for _ in range(10)]
for i in range(N+1):
  si = str(i)
  s = int(si[0])
  e = int(si[-1])
  C[s][e] += 1
ans = 0
for i in range(1,10):
  for j in range(1,10):
#    print(i,j,C[i][j])
    ans += (C[i][j] * C[j][i])
print(ans)


