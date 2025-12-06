s=int(input("Enter the starting limit"))
e=int(input("Enter the stopping limit"))
for i in range(s,e+1):
  if i<2:
    print(i,"is not a prime number")
  else:
    for j in range(2,i):
      if i%j==0:
        print(i,"is not a prime number")
        break
      else:
        print(i,"is a prime number")
        break
