N,K=map(int, input().split())

# Case : a%K = b%K = c%K = 0
nk = N // K
ans = nk * nk * nk

# Case : a%K = b%K = c%K = K/2
if K%2 == 0:
    nk = (N+K//2) // K
    ans += nk*nk*nk
print(ans)
