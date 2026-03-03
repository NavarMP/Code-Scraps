#!/bin/bash
# 24.Write a shell script to compare two files and remove one of them if they are same

if cmp -s -- "$1" "$2"; then 
    echo "same" 
    rm -i -- "$2" 
fi