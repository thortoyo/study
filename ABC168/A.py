N=int(input())
n = N % 10
if n == 3:
  print("bon")
elif n == 1 or n==0 or n==6 or n==8:
  print("pon")
else:
  print("hon")

