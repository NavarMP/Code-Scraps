#!/bin/bash
# 12. Write a shell script to count no of line, words and characters of a input file( enter file name 1.sh)

echo Enter the filename 
read file 
c=$(wc -c < "$file") 
w=$(wc -w < "$file") 
l=$(grep -c "." "$file") 
echo Number of characters in "$file" is $c 
echo Number of words in "$file" is $w 
echo Number of lines in "$file" is $l