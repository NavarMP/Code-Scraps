# 11. Write a shell script to reverse a string and check whether a given string is palindrome or not

#!/bin/bash

echo Enter the string 
    read s 
echo $s>temp 
rvs="$(rev temp)" 
if [ $s = $rvs ] 
   then 
      echo "it is palindrome" 
   else 
        echo " it is not a Palindrome" 
fi