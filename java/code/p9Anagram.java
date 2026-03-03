/*  Check given string Anagram or Not. If 
the two strings are anagram to each other, then one string can be 
rearranged to form the other string. For Example: abc and cba are anagram */


import java.util.Scanner; 
public class p9Anagram { 
    public static void main(String args[]) { 
        String str1,str2; 
        int len,len1,len2,i,j,flag=0; 
        Scanner scan=new Scanner(System.in); 
        System.out.print("Enter first string: "); 
        str1=scan.nextLine();

        System.out.print("Enter second string: "); 
        str2=scan.nextLine(); 
        len1=str1.length(); 
        len2=str2.length(); 
        if(len1==len2) { 
            len=len1; 
            for(i=0;i<len;i++) { 
                flag=0; 
                for(j=0;j<len;j++) { 
                    if(str1.charAt(i)==str2.charAt(j)) { 
                        flag=1; 
                        break; 
                    } 
                } 
                if(flag==0) { 
                    break; 
                } 
            }
            if(flag==0) { 
                System.out.println("Strings are not anagram to each other"); 
            } else { 
                System.out.println("Strings are anagram"); 
            } 
        } else { 
            System.out.println("Both Strings must have the same number of characters to be anagram"); 
        } 
    } 
}