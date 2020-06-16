A,V=map(int, input().split())
B,W=map(int, input().split())
T = int(input())
k = abs(A-B)
d = V-W
if d <= 0:
  print("NO")
else:
  if (k / d) > T:
    print("NO")
  else:
    print("YES")

