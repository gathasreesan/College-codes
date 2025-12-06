f1=open("file1.txt","r")
f2=open("write.txt","a")
for i in f1:
  if i !="\n":
    f2.write(i)
print("Non-blank files have been copied to new text file")
f1.close()
f2.close()
