str=input("Enter string")
substr=input("Enter the substring")
p=str.count(substr)
if p==0:
  print(substr,"not present in the string")
else:
  print(substr,"occurs",p,"times")
