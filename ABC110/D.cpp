S=input()
T=input()
ng = 0
ds = {}
dt = {}
for i in range(len(S)):
    if S[i] in ds:
        if ds[S[i]] != T[i]:
            ng = 1
            break;
    else:
        ds[S[i]] = T[i]
    if T[i] in dt:
        if dt[T[i]] != S[i]:
            ng = 1
            break;
    else:
        dt[T[i]] = S[i]

if ng == 0:
    print("Yes")
else:
    print("No")

