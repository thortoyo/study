N,M = map(int, input().split())

# Mの約数を求める
yaku = [ M, 1 ]
i = 2
mm = M
while (i * i) <= M:
    if mm % i == 0:
        yaku.append(i)
        yaku.append(mm//i)
    i += 1
#print(yaku)

# Mの約数の大きい順に判定していく
yaku.sort( reverse=True )

for my in yaku:
    d = M // my
    if d >= N:
        print(my)
        break

