# 4. Write a shell script to find the greatest of three numbers( enter three number in one line by space)

#!/bin/bash

echo "Enter three Integers:" 
      read a b c 
if [ $a -gt $b -a $a -gt $c ] 
   then 
       echo "$a is Greatest" 
   elif [ $b -gt $c -a $b -gt $a ] 
        then 
            echo "$b is Greatest" 
   else 
      echo "$c is Greatest!" 
fi