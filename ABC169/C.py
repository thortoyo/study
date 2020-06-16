A,B=input().split()
A=int(A)
B=int(B[0:-3] + B[-2:])
print(A*B//100)
