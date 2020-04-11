H,W,D=map(int, input().split())
A = [ [0,0] for _ in range(H*W) ]

# 番号→座標のテーブル作成
for i in range(H):
  AA = list(map(int,input().split()))
  for j in range(W):
    A[AA[j]-1][0] = i
    A[AA[j]-1][1] = j

# %D が同じ値のグループごとに累積和
M = [0] * (H*W)
for d in range(D):
  i = 1
  while (D * i + d) < (H*W) :
    pn = D * (i-1) + d
    n = D * i + d
    M[n] = M[pn] + abs(A[n][0] - A[pn][0]) + abs(A[n][1] - A[pn][1])
    i += 1

# 累積和をみて回答
Q = int(input())
for i in range(Q):
  L,R=map(int,input().split())
  print( M[R-1] - M[L-1] )

