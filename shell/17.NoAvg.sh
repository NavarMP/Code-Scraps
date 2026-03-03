#!/bin/bash
# 17. Write a shell script to find the average of the numbers entered as command line 
# arguments

sum=0 
count=1 
for x in "$@" 
do 
    if [ "$count" -eq 1 ] 
    then 
        p="$x" 
    else 
        sum=$((sum + x)) 
    fi 
    ((count++)) 
done 
echo "scale=3;$sum/$p" | bc