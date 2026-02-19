# 9. Write a shell script to find n Fibonacci numbers

#!/bin/bash

echo "How many numbers do you want of Fibonacci series ?" 
     read total 
x=0 
y=1 
i=2 
echo "Fibonacci Series up to $total terms :: " 
echo "$x" 
echo "$y" 
while [ $i -lt $total ] 
      do 
        i=`expr $i + 1 ` 
        z=`expr $x + $y ` 
        echo "$z" 
        x=$y 
        y=$z 
      done