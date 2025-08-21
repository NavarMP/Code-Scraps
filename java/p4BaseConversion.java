/*Write a program to perform base conversion 
a) Integer to binary 
b) Integer to Octal 
c) Integer to Hexadecimal  */

import java.util.Scanner; 
class Convert { 
    int num; 
    void getVal(Scanner sc) { 
        System.out.println("Decimal to Hexadecimal, Octal and Binary"); 
        System.out.print("Enter the Number: "); 
        num = sc.nextInt(); 
    }

    void convert() { 
        String hx = Integer.toHexString(num).toUpperCase(); 
        System.out.println("Hexadecimal Value: " + hx); 
        String oc = Integer.toOctalString(num); 
        System.out.println("Octal Value: " + oc); 
        String bin = Integer.toBinaryString(num); 
        System.out.println("Binary Value: " + bin); 
    } 
} 

public class p4BaseConversion {
    public static void main(String args[]) { 
        Scanner sc = new Scanner(System.in);
        Convert c = new Convert(); 
        c.getVal(sc); 
        c.convert(); 
        sc.close();
    }
}