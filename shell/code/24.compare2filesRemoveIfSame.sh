# 24.Write a shell script to compare two files and remove one of them if they are same

#!/bin/bash

# create the followings 
gedit 1.txt 
   insert datas to 1.txt  
   123456789 
 
gedit 2.txt 
   insert datas to 2.txt  
   123456789 
 
gedit 25.sh 
 
#!/bin/sh 
 
if cmp -s -- "$1" "$2"; then 
    echo "same" 
    rm -i -- "$2" 
fi 
 
# run the program like 
 
./sh 1.txt 2.txt