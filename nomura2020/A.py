H0,M0,H1,M1,K = map(int, input().split())
a = (H1*60+M1) - (H0*60+M0) - K
print(a)
