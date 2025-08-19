/*Write  a  program  to find the  sum, difference, product, quotient and 
remainder of two numbers passed as command line argument */

import java.util.Scanner;

public class p1Calc {
    public static void main(String args[]) {
        int no1, no2, sum, diff, pro, rem;
        float quotient;
        
        Scanner sc = new Scanner(System.in);
        
        System.out.println("=== Basic Calculator ===");
        
        // Input first number
        System.out.print("Enter first number: ");
        no1 = sc.nextInt();
        
        // Input second number
        System.out.print("Enter second number: ");
        no2 = sc.nextInt();
        
        // Perform calculations
        sum = no1 + no2;
        diff = no1 - no2;
        pro = no1 * no2;
        
        // Handle division with validation
        if (no2 != 0) {
            quotient = (float) no1 / no2;
            rem = no1 % no2;
        } else {
            quotient = 0;
            rem = 0;
            System.out.println("Warning: Division by zero detected. Quotient and remainder set to 0.");
        }
        
        // Display results
        System.out.println("\n=== Results ===");
        System.out.println("Sum = " + sum);
        System.out.println("Difference = " + diff);
        System.out.println("Product = " + pro);
        System.out.println("Quotient = " + quotient);
        System.out.println("Remainder = " + rem);
        
        sc.close();
    }
}
