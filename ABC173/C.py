H,W,K=map(int, input().split())
C = [ "" for _ in range(H) ]
cx = [ 0 for _ in range(H) ]
cy = [ 0 for _ in range(W) ]
for i in range(H):
  C[i] = input()
  for j in range(W):
    if C[i][j] == "#":
      cx[i] |= 1 << j
ans = 0
for y in range( 1<<H ):
  for x in range( 1<<W ):
    total = 0
    for i in range(H):
      if ( (y & (1<<i)) != 0 ):
        for j in range(W):
          if ((cx[i] & x) & (1<<j)) != 0:
            total += 1
    if total == K:
      ans += 1
print(ans)

