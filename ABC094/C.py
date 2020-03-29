N=int(input())
X=list(map(int, input().split()))
XX = sorted(X)
mid = (XX[N//2-1] + XX[N//2])/2 
for i in range(N):
  if X[i] < mid:
    print(XX[ N//2 ])
  else:
    print(XX[N//2-1])
    
