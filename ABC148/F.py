from collections import deque

INF = 1000000
N,T,A=map(int,input().split())
T -= 1
A -= 1
G = [ [] for i in range(N) ]
DT = [ INF for _ in range(N) ]
DA = [ INF for _ in range(N) ]
for i in range(N-1):
    h1,h2=map(int,input().split())
    h1 -= 1
    h2 -= 1
    G[h1].append(h2);
    G[h2].append(h1);

DT[T] = 0
DA[A] = 0

q = deque()

# BFS
q.append(T)
while len(q) > 0:
    v = q.popleft()
    for nv in G[v]:
        if DT[nv] == INF:
            DT[nv] = DT[v] + 1
            q.append(nv)

q.clear()
q.append(A)
while len(q) > 0:
    v = q.popleft()
    for nv in G[v]:
        if DA[nv] == INF:
            DA[nv] = DA[v] + 1
            q.append(nv)

max_da = 0
for i in range(N):
    #print(i, " T:", DT[i], " A:", DA[i])
    if DA[i] - DT[i] >= 1 :
        max_da = max(DA[i], max_da)
print(max_da-1)

