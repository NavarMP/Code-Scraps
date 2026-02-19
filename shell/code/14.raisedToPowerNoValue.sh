# 14. Write a shell script to find the value of one number raised to the power of another. 
# Two numbers are entered through the keyboard.

#!/bin/bash

echo "Enter a number: " 
      read a 
echo "Enter a number: " 
      read b 
echo "$(($a ** $b))"