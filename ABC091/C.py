N=int(input())
R = [ [0,0] for _ in range(N) ]
B = [ [0,0,0] for _ in range(N) ]
for i in range(N):
  R[i][0], R[i][1] = map(int, input().split())
for i in range(N):
  B[i][0], B[i][1] = map(int, input().split())

R.sort(reverse=True)

ans = 0
for i in range(N):
  bmin = 3 * N
  tgtb = -1
  for j in range(N):
    if (B[j][2] == 0) and (R[i][0] < B[j][0]) and (R[i][1] < B[j][1]):
      if bmin > B[j][1]:
        bmin = B[j][1]
        tgtb = j
  if tgtb != -1:
    ans += 1
    B[tgtb][2] = 1
print(ans)
