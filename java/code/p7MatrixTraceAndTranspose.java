/*  find the trace and transpose of a matrix */

import java.util.Scanner;
public class p7MatrixTraceAndTranspose { 
    public static void main(String args[]) { 
        int row,col,i,j,sum=0; 
        Scanner sc=new Scanner(System.in); 
        System.out.print("Enter Number of Rows: "); 
        row=sc.nextInt(); 
        System.out.print("Enter Number of Columns: "); 
        col=sc.nextInt(); 
        int mat1[][]=new int[50][50]; 
        System.out.println("Enter elements: "); 
        for(i=0;i<row;i++) { 
            for(j=0;j<col;j++) { 
                mat1[i][j]=sc.nextInt(); 
            } 
        } 

        System.out.println("Original Matrix: "); 
        for(i=0;i<row;i++) { 
            for(j=0;j<col;j++) { 
                System.out.print(" " +mat1[i][j]); 
            } 
            System.out.println(); 
        }

        System.out.println("Transpose of matrix: "); 
        for(i=0;i<col;i++) { 
            for(j=0;j<row;j++) { 
                System.out.print(" " +mat1[j][i]); 
            } 
            System.out.println(); 
        }

        if(row==col) { 
            for(i=0;i<row;i++) { 
                for(j=0;j<col;j++) { 
                    if(i==j) { 
                        sum=sum+mat1[i][j]; 
                    } 
                } 
            } 
            System.out.println("Trace = " + sum); 
        } else { 
            System.out.println("Only Square matrix contains trace."); 
        } 
    }
}
