echo "Enter a number"
read n
fact=1
if [n -eq 0]
then 
  echo "Factorial = 1"
elif [n -eq 1]
then 
  echo "Factorial =1"
fi
for i in {2 .. n}
do 
  fact= fact*i
done 
