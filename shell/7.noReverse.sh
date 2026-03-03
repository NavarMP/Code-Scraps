#!/bin/bash
# 7. Write a shell script to find reverse of a number

echo "Enter a Number:" 
read a 
rev=0 
sd=0 
or=$a 
while [ "$a" -gt 0 ] 
      do 
           sd=$((a % 10)) 
           temp=$((rev * 10)) 
           rev=$((temp + sd)) 
           a=$((a / 10)) 
      done 
echo "Reverse of $or is $rev"