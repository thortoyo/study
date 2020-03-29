S=input()
ans = "WA"
if S[0] == "A" and ("a" <= S[1] <= "z") and ("a" <= S[-1] <= "z"):
  s0 = S[2:-1]
  f = 0
  for i in range(len(s0)):
    if s0[i] == "C":
      if f != 0:
        ans = "WA"
      else:
        ans = "AC"
        f = 1

print(ans)

