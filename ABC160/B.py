X=int(input())
ans = (X//500) * 1000
X = (X % 500) // 5
print( ans + X * 5 )



