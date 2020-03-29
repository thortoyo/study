import sys
N,M=map(int,input().split())
A = list( map(int,input().split()) )
for i in range(N): A[i] = A[i]//2


def GCD(a,b):
    if a % b == 0:
        return b
    return GCD( b, a%b )

# ‘SA‚ª2‚ÅŠ„‚èØ‚ê‚é”‚ª“™‚µ‚¢‚©Šm”F
cnt = 1
while A[0]%(1<<cnt) == 0 :
    cnt += 1
for i in range(1,N):
    if (A[i]%(1<<cnt) == 0) or (A[i]%(1<<(cnt-1)) != 0):
        print(0)
        sys.exit()

A.append(1)
a = A[0]
b = A[1]
lcm = a * b // GCD(a,b)
#print(lcm)
if lcm > M:
    print(0)
    sys.exit()
for i in range(2,N):
    a = lcm
    b = A[i]
    lcm = a * b // GCD(a,b)
    if lcm > M:
        print(0)
        sys.exit()
print( (M+lcm) // (lcm*2) )
