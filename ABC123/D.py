X,Y,Z,K = map(int,input().split())
#A = np.empty(X,dtype=int)
#B = np.empty(Y,dtype=int)
#C = np.empty(Z,dtype=int)
A = sorted(list(map(int, input().split())), reverse=True)
B = sorted(list(map(int, input().split())), reverse=True)
C = sorted(list(map(int, input().split())), reverse=True)

AB = [ a+b for a in A for b in B]
AB = sorted(AB, reverse=True)
AB = AB[:3000]
ABC = [ab+c for ab in AB for c in C]
ABCs = sorted(ABC, reverse=True)[:K]
for i in range(K):
  print(ABCs[i])
  
