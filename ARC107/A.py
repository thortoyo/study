A,B,C=map(int,input().split())
MOD = 998244353
AA = A * (A+1) // 2
BA = ((AA + AA*B) * B) // 2
CBA = ((BA + BA*C) * C) // 2
CBA %= MOD
print(CBA)


