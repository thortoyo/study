H,W,Y,X=map(int, input().split())
X-=1
Y-=1
s = list()
for i in range(H):
  s.append(input())
dx = [ 0, 0, 1, -1]
dy = [ 1,-1, 0, 0 ]
ans = 1
for i in range(4):
    x,y = X,Y
    for d in range(101):
        x = x + dx[i]
        y = y + dy[i]
        if x < 0 or x >= W or y < 0 or y >= H:  break
        if s[y][x] == '#':
            break
        ans += 1
print(ans)

