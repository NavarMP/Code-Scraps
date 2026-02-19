# 22. Write a shell script to copy the contents of file to another. Input file names through 
# command line. The copy should not be allowed if second file exists. 
# (create a file gedit 133.sh and enter -this contents are present in this file)

#!/bin/bash

cat 133.sh 
 
while read line 
do 
echo "$line" 
cp 133.sh 134 
 
done<133.sh