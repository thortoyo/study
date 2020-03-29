from collections import deque

def mk_idx(y,x):
    return y*22+x

H,W=map(int, input().split())
DINF = 100000
S = []
S.append('#' * (W+2))
for i in range(H):
    S.append('#'+ input() + '#')
S.append('#' * (W+2))
dmax = 0
G = [ [] for _ in range( mk_idx(22,22) ) ]
for y in range(1,H+1):
    for x in range(1,W+1):
        if (S[y][x] == '.'):
            if (S[y-1][x] == '.'):  G[ mk_idx(y,x) ].append( mk_idx(y-1,x) )
            if (S[y][x-1] == '.'):  G[ mk_idx(y,x) ].append( mk_idx(y,x-1) )
            if (S[y+1][x] == '.'):  G[ mk_idx(y,x) ].append( mk_idx(y+1,x) )
            if (S[y][x+1] == '.'):  G[ mk_idx(y,x) ].append( mk_idx(y,x+1) )

for y in range(1,H+1):
    for x in range(1,W+1):
        if S[y][x] == '.':
            d = [ DINF for _ in range( mk_idx(22,22) ) ]
            d[ mk_idx(y,x) ] = 0
            q = deque( [mk_idx(y,x)] )
            while len(q) != 0:
                v = q.popleft()
                n = d[v];
                dmax = max(dmax, n)
                for nv in G[v]:
                    if d[ nv ] <= n+1 :
                        continue
                    d[ nv ] = n+1
                    q.append(nv)
print(dmax)

