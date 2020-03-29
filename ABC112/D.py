N,M = map(int, input().split())

# M‚Ì–ñ”‚ğ‹‚ß‚é
yaku = [ M, 1 ]
i = 2
mm = M
while (i * i) <= M:
    if mm % i == 0:
        yaku.append(i)
        yaku.append(mm//i)
    i += 1
#print(yaku)

# M‚Ì–ñ”‚Ì‘å‚«‚¢‡‚É”»’è‚µ‚Ä‚¢‚­
yaku.sort( reverse=True )

for my in yaku:
    d = M // my
    if d >= N:
        print(my)
        break

