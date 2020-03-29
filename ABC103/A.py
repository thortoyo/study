A,B,C=map(int, input().split())
d = [0,0,0]
d[0] = abs(A-B)
d[1] = abs(A-C)
d[2] = abs(C-B)
d.sort()
print(d[0]+d[1])

