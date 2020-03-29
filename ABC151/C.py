N,M=map(int, input().split())
C = [ [0,0] for _ in range(N) ]
for i in range(M):
    p, s = input().split()
    p = int(p) - 1
    if s == "AC":
        C[p][1] = 1
    else:
        if C[p][1] == 0:
            C[p][0] += 1
ans = 0
pena = 0
for i in range(N):
    if C[i][1] == 1:
        ans += 1
        pena += C[i][0]
print(ans,pena)

