def add(a,b):
  return a+b
def sub(a,b):
  return a-b
def mul(a,b):
  return a*b
def div(a,b):
  return a/b
a=int(input("Enter first number"))
b=int(input("Enter second number"))
flag=1
while(flag==1):
  print("SELECT THE REQUIRED OPTIONS\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division")
  p=int(input("Enter your choice"))
  if p==1:
    print("sum =",add(a,b))
  if p==2:
    print("difference =",sub(a,b))
  if p==3:
    print("product =",mul(a,b))
  if p==4:
    print("quotient=",div(a,b))
  flag=int(input("Enter 1 to continue"))
