#!/bin/bash
# 16. An employee Basic Pay is input through keyboard where DA is 40% of basic pay 
# and HRA is 20% of basic pay. Write a shell script to calculate gross salary, Gross 
# Salary =Basic Pay + DA + HRA

echo "enter the basic salary:" 
read basal 
grosal=$(echo "$basal+((40/100)*$basal)+((20/100)*$basal)" | bc -l) 
echo "The gross salary : $grosal"