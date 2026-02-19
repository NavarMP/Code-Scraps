# 1. Write a shell script to find area of a circle

#!/bin/bash

echo "Enter the radius : " 
      read r 
echo "Area of the Circle is" 
echo "3.14 * $r * $r" | bc
