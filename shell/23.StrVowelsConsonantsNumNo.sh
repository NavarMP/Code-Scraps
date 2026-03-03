#!/bin/bash
# 23. Write a shell script to find number of vowels, consonants, numbers in a given string.

echo -n "Enter a line of text: " 
read string 
 
numCount=$(echo "$string" | grep -o "[0-9]" | wc -l) 
vowCount=$(echo "$string" | grep -o -i "[aeiou]" | wc -l) 
consCount=$(echo "$string" | grep -o -i "[bcdfghjklmnpqrstvwxyz]" | wc -l) 
 
echo "The given string has $vowCount vowels, $consCount consonants and $numCount numbers in it."