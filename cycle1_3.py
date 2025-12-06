L=[]
x=int(input("Enter size of the list"))
for i in range(0,x):
  l=int(input("Enter the list element"))
  L.append(l)
q=int(input("Enter the element you want to search"))
found=False
for j in range(0,x):
  if L[j]==q:
    print(q,"found in index",j)
    found=True
if found==False:
  print(q,"not found in the list")
