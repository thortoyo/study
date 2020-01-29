import fractions
from functools import reduce

def lcm_base(x, y):
    return (x * y) // fractions.gcd(x, y)

def lcm_list(numbers):
    return reduce(lcm_base, numbers, 1)

N=int(input())
A = list(map(int,input().split()))
MOD = 1000000007

lcm = lcm_list(A)
ans = 0
for i in range(N):
  ans = (ans + (lcm // A[i]))
print(ans % MOD)





