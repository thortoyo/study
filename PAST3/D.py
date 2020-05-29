N=int(input())
s = []
for i in range(5):
  ss = input()
  s.append(ss)
ans = ""
for i in range(N):
  si = [ s[x][i*4+1:(i+1)*4] for x in range(5) ]
  if si[1] == "#.#" and si[2] == "#.#" and si[3] == "#.#":
    ans += "0"
  elif si[1] == "##." and si[2] == ".#." and si[3] == ".#.":
    ans += "1"
  elif si[1] == "..#" and si[2] == "###" and si[3] == "#..":
    ans += "2"
  elif si[1] == "..#" and si[2] == "###" and si[3] == "..#":
    ans += "3"
  elif si[1] == "#.#" and si[2] == "###" and si[3] == "..#" and si[4] == "..#":
    ans += "4"
  elif si[1] == "#.." and si[2] == "###" and si[3] == "..#":
    ans += "5"
  elif si[1] == "#.." and si[2] == "###" and si[3] == "#.#":
    ans += "6"
  elif si[1] == "..#" and si[2] == "..#" and si[3] == "..#":
    ans += "7"
  elif si[1] == "#.#" and si[2] == "###" and si[3] == "#.#":
    ans += "8"
  else:
    ans += "9"
print(ans)
