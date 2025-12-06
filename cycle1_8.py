d={}
n=int(input("Enter the number of persons: "))
for i in range(n):
  name = input("Enter name of the person: ")
  phone= int(input("Enter phone number"))
  d[name]=phone
print("Phonebook Dictionary")
print(d)
