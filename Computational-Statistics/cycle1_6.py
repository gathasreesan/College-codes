L=[]
x=int(input("Enter size of elements"))
for i in range(0,x):
  p=int(input("Enter element :"))
  L.append(p)
sqr=[]
for j in L:
  sqr.append(j*j)
print("List of squared numbers :",sqr)
sum=0
count=0
for k in sqr:
  sum=sum+k
  count=count+1
print("Average of the squared numbers=",sum/count)
