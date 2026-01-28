echo "Enter a number"
read n
fact=1
if [ $n -eq 0 ]
then 
  echo "Factorial = 1"
elif [ $n -eq 1 ]
then 
  echo "Factorial =1"
fi
for ((i=2; i<=n; i++))
do 
  fact=$((fact*i))
done 
echo "Factorial = $fact"
