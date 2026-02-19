echo "Sd=$sd"
6. Write a shell script to find sum of all digits from a given number
echo "Enter a Number:"
read n
temp=$n
sd=0
sum=0
while [ $n -gt 0 ]
do
sd=$(( $n % 10 ))
n=$(( $n / 10 ))
sum=$(( $sum + $sd ))
done
echo "Sum is $sum"
7. Write a shell script to find reverse of a number
echo "Enter a Number:"
read a
rev=0
sd=0
or=$a
while [ $a -gt 0 ]
do
sd=`expr $a % 10`
temp=`expr $rev \* 10`
rev=`expr $temp + $sd`
a=`expr $a / 10`
done
echo "Reverse of $or is $rev"
8. Write a shell script to find prime numbers up to a given number
echo "Enter a limit"
read limit
echo "prime numbers upto $limit are :"
echo "1"
i=2
while [ $i -le $limit ]
do
flag=1
j=2
while [ $j -lt $i ]
do
rem=$(( $i % $j ))
if [ $rem -eq 0 ]
then
flag=0
break
fi
j=$(( $j+1 ))
done
if [ $flag -eq 1 ]
then
echo "$i"
fi
i=$(( $i+1 ))
done
