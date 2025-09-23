import java.util.Scanner; 
 
public class p23fibonacciUpToLt {
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
 
        // Input limit from user 
        System.out.print("Enter the limit: "); 
        int limit = sc.nextInt(); 
 
        int first = 0, second = 1; 
 
        System.out.println("Fibonacci series up to " + limit + ":"); 
         
        // Print Fibonacci numbers until the value exceeds the limit 
        while (first <= limit) { 
            System.out.print(first + " "); 
            int next = first + second; 
            first = second; 
            second = next; 
        } 
 
        sc.close(); 
    } 
}

