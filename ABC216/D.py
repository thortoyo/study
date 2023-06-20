# 筒の一番上にあるボールの番号をインデックスとしたリストを作る
# そのリストを見に行って、値が0なら、筒番号をリストに書き込む。
# なので、リストのインデックスは 1 始まりにする。
# 値が0じゃないなら、同じ番号のボールがすでに登録済みということが分かるので、
# 現在見ている筒番号と、リストに書かれていた筒番号の筒の、一番上のボールをpopして、
# 次の一番上のボールの番号を見る。
# これで O(N+M) で終わるはず
# 筒は、FIFOが構成出来ればいいので、リストの逆順にするか、キューにする
# 1 <= N <= 2×10^5
# 2 <= M <= 2×10^5

import sys
from collections import deque

sys.setrecursionlimit(2000000)

N,M=map(int, input().split())

d = [ 0 ]
b1 = [ 0 for _ in range(N+1) ]

def get_top( num ):
  if ( len(d[num]) == 0 ):
    return -1
  aa = d[num].popleft()
  if ( b1[aa] == 0 ):
    b1[aa] = num
  else:
    tmp = b1[aa]
    b1[aa] = 0
    get_top( num )
    get_top( tmp )

for i in range(1,M+1):
  k=int(input())
  dm = deque()
  alist = map(int, input().split())
  for a in alist:
    dm.append(a)
  d.append(dm)
  get_top( i )

ng = 0
for i in range(1,M+1):
#  print(d[i])
  if len(d[i]) != 0:
    ng = 1
for i in range(N+1):
  if b1[i] != 0:
    ng = 1
if ng == 0:
  print("Yes")
else:
  print("No")


