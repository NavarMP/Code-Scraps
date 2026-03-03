#!/bin/bash
# 10. Write a shell script to check whether a given number is Armstrong or not 

echo "Enter a number: " 
read c 
x=$c 
sum=0 
r=0 
n=0 
while [ "$x" -gt 0 ] 
      do 
            r=$((x % 10)) 
            n=$((r * r * r)) 
            sum=$((sum + n)) 
            x=$((x / 10)) 
      done 
if [ "$sum" -eq "$c" ] 
      then 
            echo "It is an Armstrong Number." 
      else 
            echo "It is not an Armstrong Number." 
fi