/*Write a program to perform base conversion 
a) Integer to binary 
b) Integer to Octal 
c) Integer to Hexadecimal  */

import java.util.Scanner; 
class Convert { 
    Scanner sc; 
    int num; 
    void getVal() { 
        System.out.println("Decimal to Hexa Decimal, Octal and Binary"); 
        sc=new Scanner(System.in); 
        System.out.println("Enter the Number: "); 
        num=Integer.parseInt(sc.nextLine()); 
    }

    void convert() { 
        String hx=Integer.toHexString(num); 
        System.out.println("HexaDecimal Value: " + hx); 
        String oc=Integer.toOctalString(num); 
        System.out.println("Octal value: " + oc); 
        String bin=Integer.toBinaryString(num); 
        System.out.println("Binary value: " + bin); 
    } 
} 

public class p4BaseConversion {
    public static void main(String args[]) { 
        Convert c=new Convert(); 
        c.getVal(); 
        c.convert(); 
    } 
}
