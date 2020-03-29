import sys
N=int(input())
po = []
zp = []
for i in range(N):
    x, y, h = map(int, input().split())
    if h == 0:
        zp.append( [x,y] )
    else:
        po.append( [x,y,h] )
for yt in range(101):
    for xt in range(101):
        k = -1
        for p in po:
            tmpH = p[2] + abs(p[0]-xt) + abs(p[1]-yt)
            if k == -1:
                k = tmpH
            else:
                if k != tmpH:
                    k = -1
                    break
        if k == -1:
            continue
        for p in zp:
            if (k - abs(p[0]-xt) - abs(p[1]-yt)) > 0:
                k = -1
                break
        if k != -1:
            print(xt,yt,k)
            sys.exit
