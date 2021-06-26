a,b,c=map(int, input().split())
print(max(a+b, max(a+c, b+c)))
