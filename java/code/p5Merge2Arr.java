// merge two arrays.

import java.util.Scanner; 
public class p5Merge2Arr { 
    public static void main(String args[]) { 
        int n1, n2, k; 
        int c[] = new int[100]; // Increased size for safety
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number of elements in 1st array: "); 
        n1 = sc.nextInt(); 
        int a[] = new int[n1]; 
        System.out.println("Enter the 1st array elements: "); 
        for (int i = 0; i < n1; i++) { 
            a[i] = sc.nextInt(); 
            c[i] = a[i]; 
        }

        k = n1;
        System.out.println("Enter number of elements in 2nd array: "); 
        n2 = sc.nextInt(); 
        int b[] = new int[n2]; 
        System.out.println("Enter the 2nd array elements: "); 
        for (int i = 0; i < n2; i++) { 
            b[i] = sc.nextInt(); 
            c[k] = b[i]; 
            k++; 
        }

        System.out.println("1st array: "); 
        for (int i = 0; i < n1; i++) { 
            System.out.print(" " + a[i]); 
        }

        System.out.println();

        System.out.println("2nd array: "); 
        for (int i = 0; i < n2; i++) { 
            System.out.print(" " + b[i]); 
        }

        System.out.println(); 

        System.out.println("Merged array: "); 
        for (int i = 0; i < k; i++) { 
            System.out.print(" " + c[i]); 
        }
        sc.close(); // Close the Scanner to avoid resource leak
    } 
}