/* find  the  sum  of  the  digits  and  reverse  of  a  given 
number using class and objects */


import java.util.Scanner; 
class sumRev { 
    int rem,m,sum; 
    sumRev() { 
        m=0; 
        sum=0; 
        rem=0; 
    } 
    void reverse(int n) { 
        do { 
            rem=n%10; 
            m=m*10+rem; 
            n=n/10; 
        }
        while(n>0); 
        System.out.println("Reverse = " + m); 
    } 
    void digit(int n) { 
        rem=0; 
        do { 
            rem=n%10; 
            sum=sum+rem; 
            n=n/10;
        } while(n>0);

        System.out.println("Sum of the digits = " + sum); 
    }
} 
 
class p8DigSumAndReverse { 
    public static void main(String args[]) { 
        Scanner sc = new Scanner(System.in); 

        System.out.print("Enter a number: "); 
        int num = sc.nextInt();
        sumRev obj=new sumRev();

        obj.reverse(num); 
        obj.digit(num);

        sc.close();
    } 
}