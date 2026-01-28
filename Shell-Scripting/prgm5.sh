echo "Enter a number"
read a
while [a -gt 0]
do
  r=$((a%10))
  sum=$((sum+r))
  a=$((a/10))
done
