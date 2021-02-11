H,W=map(int, input().split())
S = []
for i in range(H):
  s = input()
  S.append(s)
dx = [1,0,-1,0]
dy = [0,1,0,-1]
ans = 0
for y in range(1,H-1):
  for x in range(1,W-1):
    tmp = 0
    for i in range(4):
      if (S[y][x] == S[y+dy[i]][x+dx[i]]):  tmp+=1
#    print(tmp,end=" ")
    if tmp == 1:
      ans += 2
    elif tmp == 2:
      if (S[y+1][x] != S[y-1][x]):
        ans += 1
    elif tmp == 0:
        ans += 4
#  print()
print(ans)

