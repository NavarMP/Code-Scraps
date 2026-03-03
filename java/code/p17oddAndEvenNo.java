import java.io.*;
import java.util.Scanner;

class Even implements Runnable { 
    Thread even; 
    int limit,i; 
    Even(int a) { 
        even=new Thread(this,"Even"); 
        limit=a; 
        even.start(); 
    } 
    public void run() { 
        try { 
            for(i=2;i<limit;i=i+2) { 
                System.out.println(i); 
                Thread.sleep(500); 
            } 
        } 
        catch(Exception e) { 
            System.out.println(e); 
        } 
    }
} 
     
class Odd implements Runnable { 
    Thread odd; 
    int limit,i; 
    Odd(int b) { 
        odd=new Thread(this,"Odd"); 
        limit=b; 
        odd.start(); 
    }
    public void run() { 
        try { 
            for(i=1;i<limit;i=i+2) { 
                System.out.println("\t" + i); 
                Thread.sleep(500); 
            } 
        } 
        catch(Exception e) { 
            System.out.println(e); 
        } 
    } 
} 

public class p17oddAndEvenNo { 
    public static void main (String args[]) throws IOException { 
        int n1,n2; 
        Scanner sc=new Scanner(System.in); 
        System.out.println("Enter limit of even numbers"); 
        n1=sc.nextInt(); 
        System.out.println("Enter limit of odd numbers"); 
        n2=sc.nextInt(); 
        Even en=new Even(n1); 
        Odd od=new Odd(n2); 
        try { 
            Thread.sleep(10000); 
        }
        catch(Exception e) { 
            System.out.println(e); 
        }
    }
}