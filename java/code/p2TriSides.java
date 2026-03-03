/* Given the sides of a triangle,
check whether the triangle is
equilateral, isosceles or scalene and find its area.
*/

import java.util.*;
public class p2TriSides {
    public static void main(String args[]) { 
        Scanner sc = new Scanner(System.in); 
        double a, b, c; // Use double for sides to allow non-integer input
        System.out.println("Enter 3 sides:"); 
        a = sc.nextDouble(); 
        b = sc.nextDouble(); 
        c = sc.nextDouble(); 

        // Check for triangle validity
        if (a > 0 && b > 0 && c > 0 && a < b + c && b < a + c && c < a + b) { 
            if (a == b && b == c) 
                System.out.println("Equilateral triangle"); 
            else if (a == b || b == c || c == a) 
                System.out.println("Isosceles triangle"); 
            else 
                System.out.println("Scalene triangle"); 

            double s = (a + b + c) / 2; 
            double val = s * (s - a) * (s - b) * (s - c); 
            if (val <= 0) {
                System.out.println("Area cannot be calculated (invalid triangle sides).");
            } else {
                double area = Math.sqrt(val); 
                System.out.println("Area of the triangle is: " + area); 
            }
        } else {
            System.out.println("Cannot form a triangle"); 
        } 
    }
}