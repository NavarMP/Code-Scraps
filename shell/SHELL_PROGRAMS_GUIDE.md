# Shell Programming Guide: Selected Programs

A curated list of simple shell scripts from the `shell` folder intended for beginners. The scripts chosen are easy to understand and cover a variety of basic concepts.

---

## 1. Circle Area Calculation (`1.circleArea.sh`)
**Purpose:** Calculate the area of a circle given its radius.

**Algorithm:**
1. Read radius `r` from the user.
2. Calculate area as `3.14 * r * r`.
3. Display the computed area.

```bash
#!/bin/bash

echo "Enter the radius : " 
read r 
echo "Area of the Circle is" 
echo "3.14 * $r * $r" | bc
```

**Example Output:**
```
$ ./1.circleArea.sh
Enter the radius : 
5
Area of the Circle is
78.5
```

---

## 2. Even or Odd Checker (`2.evenOdd.sh`)
**Purpose:** Determine if a number is even or odd.

**Algorithm:**
1. Read number `n`.
2. Find remainder `rem = n % 2`.
3. If `rem` is `0`, print "even number".
4. Otherwise, print "odd number".

```bash
#!/bin/bash

echo "Enter a number : " 
read n 
rem=$((n % 2)) 
if [ "$rem" -eq 0 ] 
then 
    echo "$n is even number" 
else 
    echo "$n is odd number" 
fi
```

**Example Output:**
```
$ ./2.evenOdd.sh
Enter a number : 
7
7 is odd number
```

---

## 3. Menu-driven Calculator (`3.menuCalc.sh`)
**Purpose:** Perform simple arithmetic using a case-based menu.

**Algorithm:**
1. Read two numbers `n1` and `n2`.
2. Repeat the following while user chooses to continue:
   a. Display arithmetic operations menu.
   b. Read user choice `ch`.
   c. Perform operation (Add, Sub, Mul, Div) based on `ch` and print result.
   d. Ask if the user wants to continue.

```bash
#!/bin/bash
# Write a shell script to make a menu driven calculator using case

sum=0 
i="y" 
echo "Enter first number :" 
read n1 
echo "Enter second number :" 
read n2 
while [ "$i" = "y" ] 
do 
    echo "1.Addition" 
    echo "2.Subtraction" 
    echo "3.Multiplication" 
    echo "4.Division" 
    echo "Enter your choice" 
    read ch 
    case $ch in 
        1)sum=`expr $n1 + $n2` 
          echo "Sum ="$sum;; 
        2)sub=`expr $n1 - $n2` 
          echo "Sub = "$sub;; 
        3)mul=`expr $n1 \* $n2` 
          echo "Mul = "$mul;; 
        4)div=`echo $n1 / $n2 | bc -l` 
          echo "Div = "$div;; 
        *)echo "Invalid choice";; 
    esac 
    echo "Do u want to continue ?" 
    read i 
    if [ "$i" != "y" ] 
    then 
        exit 
    fi 
done
```

**Example Output (interaction):**
```
$ ./3.menuCalc.sh
Enter first number :
4
Enter second number :
5
1.Addition
2.Subtraction
3.Multiplication
4.Division
Enter your choice
1
Sum =9
Do u want to continue ?
n
```

---

## 4. Greatest of Three Numbers (`4.greatOf3No.sh`)
**Purpose:** Identify the largest of three input integers.

**Algorithm:**
1. Read three integers `a`, `b`, and `c`.
2. If `a` is greater than both `b` and `c`, `a` is the greatest.
3. Else if `b` is greater than both `c` and `a`, `b` is the greatest.
4. Else, `c` is the greatest.
5. Print the greatest number.

```bash
#!/bin/bash

# 4. Write a shell script to find the greatest of three numbers( enter three number in one line by space)

echo "Enter three Integers:" 
read a b c 
if [ "$a" -gt "$b" -a "$a" -gt "$c" ] 
then 
    echo "$a is Greatest" 
elif [ "$b" -gt "$c" -a "$b" -gt "$a" ] 
then 
    echo "$b is Greatest" 
else 
    echo "$c is Greatest!" 
fi
```

**Example Output:**
```
$ ./4.greatOf3No.sh
Enter three Integers:
3 9 5
9 is Greatest
```

---

## 5. Sum of Digits (`6.digitsSum.sh`)
**Purpose:** Compute the sum of all digits of a number.

**Algorithm:**
1. Read a number `n`.
2. Initialize `sum = 0`.
3. While `n > 0`:
   a. Extract last digit `sd = n % 10`.
   b. Add `sd` to `sum`.
   c. Remove last digit `n = n / 10`.
4. Print the final `sum`.

```bash
#!/bin/bash

# 6. Write a shell script to find sum of all digits from a given number

echo "Enter a Number:" 
read n 
temp=$n 
sd=0 
sum=0 
while [ "$n" -gt 0 ] 
do 
    sd=$((n % 10)) 
    n=$((n / 10)) 
    sum=$((sum + sd)) 
done 
echo "Sum is $sum"
```

**Example Output:**
```
$ ./6.digitsSum.sh
Enter a Number:
1234
Sum is 10
```

---

## 6. Prime Numbers Up To Limit (`8.primeNoUpto.sh`)
**Purpose:** List primes less than or equal to a given limit.

**Algorithm:**
1. Read a `limit`.
2. Print `1` as prime.
3. For each number `i` from `2` to `limit`:
   a. Check if `i` is divisible by any number `j` from `2` to `i-1`.
   b. If no divisor is found, `i` is prime, and print `i`.

```bash
#!/bin/bash

# 8. Write a shell script to find prime numbers up to a given number

echo "Enter a limit" 
read limit 
echo "prime numbers upto $limit are :" 
echo "1" 
i=2 
while [ "$i" -le "$limit" ] 
do 
    flag=1 
    j=2     
    while [ "$j" -lt "$i" ] 
do 
           rem=$((i % j)) 
           if [ "$rem" -eq 0 ] 
              then 
                flag=0 
              break 
           fi 
           j=$((j+1)) 
done 
    if [ "$flag" -eq 1 ] 
    then 
       echo "$i" 
    fi 
i=$((i+1)) 
done
```

**Example Output:**
```
$ ./8.primeNoUpto.sh
Enter a limit
10
prime numbers upto 10 are :
1
2
3
5
7
```

---

## 7. Fibonacci Series (`9.fibonacciNo.sh`)
**Purpose:** Output a specified number of Fibonacci terms.

**Algorithm:**
1. Read total number of terms `total`.
2. Initialize `x = 0`, `y = 1` and print them.
3. For `i` from `2` to `total - 1`:
   a. Calculate next term `z = x + y`.
   b. Print `z`.
   c. Update `x = y` and `y = z`.

```bash
#!/bin/bash

# 9. Write a shell script to find n Fibonacci numbers

echo "How many numbers do you want of Fibonacci series ?" 
read total 
x=0 
y=1 
i=2 
echo "Fibonacci Series up to $total terms :: " 
echo "$x" 
echo "$y" 
while [ "$i" -lt "$total" ] 
do 
    i=$((i + 1)) 
    z=$((x + y)) 
    echo "$z" 
    x=$y 
    y=$z 
done
```

**Example Output:**
```
$ ./9.fibonacciNo.sh
How many numbers do you want of Fibonacci series ?
5
Fibonacci Series up to 5 terms :: 
0
1
1
2
3
```

---

## 8. String Reversal & Palindrome Check (`11.revStrAndPalindrome.sh`)
**Purpose:** Reverse an input string and test for palindrome.

**Algorithm:**
1. Read string `s` and store it in a temporary file.
2. Reverse the content of the file to get `rvs`.
3. Compare `s` and `rvs`.
4. If they match, print "it is palindrome". Otherwise, print "it is not a Palindrome".

```bash
#!/bin/bash

# 11. Write a shell script to reverse a string and check whether a given string is palindrome or not

echo Enter the string 
read s 
echo "$s" > temp 
rvs="$(rev temp)" 
if [ "$s" = "$rvs" ] 
then 
    echo "it is palindrome" 
else 
    echo " it is not a Palindrome" 
fi
```

**Example Output:**
```
$ ./11.revStrAndPalindrome.sh
Enter the string
level
it is palindrome
```

---

## 9. File Statistics (`12.filecountLineWordCharNo.sh`)
**Purpose:** Report lines, words and characters in a given file.

**Algorithm:**
1. Read filename `file`.
2. Count characters using `wc -c < file`.
3. Count words using `wc -w < file`.
4. Count lines using `grep -c "." file` (non-empty lines).
5. Display the character, word, and line counts.

```bash
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
```

**Example Output:**
```
$ ./12.filecountLineWordCharNo.sh
Enter the filename
test.txt
Number of characters in "test.txt" is 42
Number of words in "test.txt" is 8
Number of lines in "test.txt" is 3
```

---

## 10. Power Calculation (`14.raisedToPowerNoValue.sh`)
**Purpose:** Raise one number to the power of another.

**Algorithm:**
1. Read base number `a` and exponent number `b`.
2. Compute `a ** b`.
3. Print the result.

```bash
#!/bin/bash

# 14. Write a shell script to find the value of one number raised to the power of another. 
# Two numbers are entered through the keyboard.

echo "Enter a number: " 
read a 
echo "Enter a number: " 
read b 
echo "$((a ** b))"
```

**Example Output:**
```
$ ./14.raisedToPowerNoValue.sh
Enter a number: 
2
Enter a number: 
3
8
```

---

## 11. Factorial Calculation (`15.NoFactorial.sh`)
**Purpose:** Compute factorial of a given number.

**Algorithm:**
1. Read number `num`.
2. Initialize `fact = 1`.
3. While `num > 1`:
   a. Multiply `fact` by `num`.
   b. Decrement `num` by `1`.
4. Print the calculated `fact`.

```bash
#!/bin/bash

# 15. Write a shell script find the factorial of a given number

echo "Enter a number" 
read num 
fact=1 
while [ "$num" -gt 1 ] 
do 
    fact=$((fact * num)) 
    num=$((num - 1)) 
done 
echo "Factorial=$fact"
```

**Example Output:**
```
$ ./15.NoFactorial.sh
Enter a number
5
Factorial=120
```

---

## 12. Banner and Calendar Display (`18.dispBannerCalendar.sh`)
**Purpose:** Show a welcome banner and calendar for an entered year.

**Algorithm:**
1. Print a welcome banner.
2. Read the `year`.
3. Run the `cal` command with `year` to display the calendar.

```bash
#!/bin/bash

# 19. Write a shell script to Display Banner, calendar of given year

echo "==============================" 
echo "      WELCOME TO MY SHELL     " 
echo "==============================" 
 
echo "Enter the year:" 
read year 
 
echo "Calendar for the year $year:" 
cal "$year"
```

**Example Output:**
```
$ ./19.dispBannerCalendar.sh
==============================
      WELCOME TO MY SHELL     
==============================
Enter the year:
2025
Calendar for the year 2025:
     January               February              March
Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa
 1  2  3  4  5  6  7   1  2  3  4  5  6  7   1  2  3  4  5  6  7
...
```

---

## 13. System Information Display (`20.DateTimeUsersNoTermNameLoginDT.sh`)
**Purpose:** Print date/time, user list, terminal, login info.

**Algorithm:**
1. Clear the screen.
2. Print current date and time using `date`.
3. Print terminal name using `tty`.
4. Print current users using `users`.
5. Print login info utilizing the `w` command.

```bash
#!/bin/bash

# 20. Write a shell script to display current date and time, number of users, terminal 
# name, login date and time

clear 
echo "current date and time : $(date)" 
echo "terminal name : $(tty)" 
echo "users : $(users)" 
echo "login date time : $(w)"
```

**Example Output:**
```
current date and time : Tue Mar  3 14:20:00 PST 2026
tty name : /dev/ttys001
users : apple
tty=ttys001  :0               Mar 3 14:00
```

---

## 14. Vowels, Consonants, Numbers Count (`23.StrVowelsConsonantsNumNo.sh`)
**Purpose:** Count vowels, consonants, and digits in a string.

**Algorithm:**
1. Read string `string`.
2. Count digits using `grep -o "[0-9]" | wc -l`.
3. Count vowels using `grep -o -i "[aeiou]" | wc -l`.
4. Count consonants using `grep -o -i "[bcdfghjklmnpqrstvwxyz]" | wc -l`.
5. Print the counts.

```bash
#!/bin/bash

# 23. Write a shell script to find number of vowels, consonants, numbers in a given string.

echo -n "Enter a line of text: " 
read string 
 
numCount=$(echo "$string" | grep -o "[0-9]" | wc -l) 
vowCount=$(echo "$string" | grep -o -i "[aeiou]" | wc -l) 
consCount=$(echo "$string" | grep -o -i "[bcdfghjklmnpqrstvwxyz]" | wc -l) 
 
echo "The given string has $vowCount vowels, $consCount consonants and $numCount numbers in it."
```

**Example Output:**
```
$ ./23.StrVowelsConsonantsNumNo.sh
Enter a line of text: Hello123
The given string has 2 vowels, 3 consonants and 3 numbers in it.
```

---

## 15. File Operations Menu (`25.fileOperationsMenu.sh`)
**Purpose:** Perform file operations like display, list, make directory, copy, rename, and delete.

**Algorithm:**
1. Display file operations menu.
2. Read user `choice`.
3. Based on `choice`, read required inputs (e.g., filename):
   a. 1: Display file content (`cat`).
   b. 2: List files (`ls`).
   c. 3: Make directory (`mkdir`).
   d. 4: Copy file (`cp`).
   e. 5: Rename file (`mv`).
   f. 6: Delete file (`rm`).
4. Read choice until user selects Exit.

```bash
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
```

**Example Output (interaction):**
```
$ ./25.fileOperationsMenu.sh
===== Simple File Operations Menu =====
1. Display File Content
2. List Files
3. Make Directory
4. Copy File
5. Rename File
6. Delete File
7. Exit
Enter your choice: 2
Files in current directory:
1.circleArea.sh    2.evenOdd.sh    3.menuCalc.sh
```

---

## Concepts Covered

This selection touches on arithmetic, conditionals, loops, string manipulation, file I/O and system commands.

**Note:** numbers refer to original filenames.

---

**Last Updated:** March 3, 2026
