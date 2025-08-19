/*Read an array of 10 or more numbers and write a program to find the 
a) Smallest element in the array 
b) Largest element in the array 
c) Second largest element in the array */

import java.util.*;
public class p3ReadArr {
    public static void main(String args[]) { 
        int a; 
        int arr[]={55,10,8,90,43,87,95,25,50,12}; 
        System.out.println("Array = " + Arrays.toString(arr)); 
        int count=arr.length; 
        for(int i=0;i<count;i++) { 
            for(int j=i+1;j<count;j++) { 
                if(arr[i]>arr[j]) { 
                    a=arr[i]; 
                    arr[i]=arr[j]; 
                    arr[j]=a; 
                } 
            } 
        }
        System.out.println("Sorted Array= " + Arrays.toString(arr)); 
        System.out.println("Smallest: " + arr[0]); 
        System.out.println("Largest: " + arr[count - 1]); 
        System.out.println("Second largest: " + arr[count - 2]); 
    } 
}
