N,M = map(int, input().split())

# M�̖񐔂����߂�
yaku = [ M, 1 ]
i = 2
mm = M
while (i * i) <= M:
    if mm % i == 0:
        yaku.append(i)
        yaku.append(mm//i)
    i += 1
#print(yaku)

# M�̖񐔂̑傫�����ɔ��肵�Ă���
yaku.sort( reverse=True )

for my in yaku:
    d = M // my
    if d >= N:
        print(my)
        break

