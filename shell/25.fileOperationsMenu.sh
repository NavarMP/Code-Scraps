#!/bin/bash

echo "===== Simple File Operations Menu ====="
echo "1. Display File Content"
echo "2. List Files"
echo "3. Make Directory"
echo "4. Copy File"
echo "5. Rename File"
echo "6. Delete File"
echo "7. Exit"

read -p "Enter your choice: " choice

case $choice in
    1)
        read -p "Enter file name to display: " file
        cat "$file"
        ;;
    2)
        echo "Files in current directory:"
        ls
        ;;
    3)
        read -p "Enter directory name: " dir
        mkdir "$dir"
        echo "Directory created."
        ;;
    4)
        read -p "Enter source file: " src
        read -p "Enter destination file: " dest
        cp "$src" "$dest"
        echo "File copied."
        ;;
    5)
        read -p "Enter old file name: " old
        read -p "Enter new file name: " new
        mv "$old" "$new"
        echo "File renamed."
        ;;
    6)
        read -p "Enter file name to delete: " del
        rm "$del"
        echo "File deleted."
        ;;
    7)
        echo "Exiting..."
        exit 0
        ;;
    *)
        echo "Invalid choice!"
        ;;
esac
