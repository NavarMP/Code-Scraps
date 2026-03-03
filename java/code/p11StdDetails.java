/* Create a class Student to read and display the student details. Create another class 
mark inherit from student to read marks of 5 subjects and find total and average. 
Write a Java program to display the result of a student. */

import java.util.Scanner; 
class student {
    int  admNo; 
    Scanner sc; 
    student() { 
        sc = new Scanner(System.in); 
    } 
    void read() { 
        System.out.print("Enter Admission number: ");
        admNo = sc.nextInt();
    } 
    void display() {
        System.out.print(admNo + "\t"); 
    }
} 
 
class mark extends student {
    int mark[];
    int total;
    int avg;
    int i;
    String result; 
    mark() { 
        super(); 
        mark = new int[5]; 
        total = 0; 
        avg = 0; 
    }
    void read() { 
        super.read(); 
        System.out.print("Enter 5 subject marks: "); 
        for (i = 0; i < 5; i++) { 
            System.out.println("Enter subject[" + (i + 1) + "]: "); 
            mark[i] = sc.nextInt();
        }
    } 
    void calculate() { 
        for (i = 0; i < 5; i++) { 
            total = total + mark[i]; 
        } 
        avg = total / 5; 
        if (total >= 175) { 
            result ="PASSED"; 
        } else { 
            result = "FAILED"; 
        } 
    } 
    void display() { 
        super.display(); 
        System.out.println("\t" + result); 
    } 
} 
public class p11StdDetails { 
    public static void main(String[] args) {
        mark m[];
        int j = 0;
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Number of Students: ");
        n = sc.nextInt();
        m = new mark[n];
        for (j = 0; j < n; j++) {
            m[j] = new mark();
            System.out.print("Enter [" + (j + 1) + "] Student details: ");
            m[j].read();
            m[j].calculate();
        }
        System.out.println("Student Details: ");
        System.out.println("Adm Number\tResult: ");
        for (j = 0; j < n; j++) {
            m[j].display();
        }

        sc.close();
    }
}