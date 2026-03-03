#!/bin/bash
# 20. Write a shell script to display current date and time, number of users, terminal 
# name, login date and time

clear 
echo "current date and time : $(date)" 
echo "terminal name : $(tty)" 
echo "users : $(users)" 
echo "login date time : $(w)"