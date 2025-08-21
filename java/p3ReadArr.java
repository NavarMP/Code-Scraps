/*Read an array of 10 or more numbers and write a program to find the 
a) Smallest element in the array 
b) Largest element in the array 
c) Second largest element in the array */

import java.util.*;
public class p3ReadArr {
    public static void main(String args[]) { 
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements (10 or more): ");
        int count = sc.nextInt();
        if (count < 10) {
            System.out.println("Please enter at least 10 elements.");
            sc.close();
            return;
        }
        int arr[] = new int[count];
        System.out.println("Enter " + count + " elements:");
        for (int i = 0; i < count; i++) {
            arr[i] = sc.nextInt();
        }

        // Sort the array
        Arrays.sort(arr);

        System.out.println("Array = " + Arrays.toString(arr));
        System.out.println("Smallest: " + arr[0]);
        System.out.println("Largest: " + arr[count - 1]);
        System.out.println("Second largest: " + arr[count - 2]);
        sc.close();
    } 
}
