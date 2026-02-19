# 19. Write a shell script to Display Banner, calendar of given year

#!/bin/bash

# Display Banner 
echo "==============================" 
echo "      WELCOME TO MY SHELL     " 
echo "==============================" 
 
# Ask user for the year 
echo "Enter the year:" 
read year 
 
# Display the calendar for the given year 
echo "Calendar for the year $year:" 
cal $year 