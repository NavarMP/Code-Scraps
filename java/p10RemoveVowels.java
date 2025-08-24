/* remove all vowels from a string */

import java.util.Scanner; 
public class p10RemoveVowels { 
    public static void main(String args[]) {
        String str1,str2; 
        Scanner sc=new Scanner(System.in); 
        System.out.print("Enter a String: "); 
        str1=sc.nextLine(); 
        str2=str1.replaceAll("[aeiouAEIOU]"," "); 
        System.out.println("All vowels removed successfully"); 
        System.out.println(str2); 
    } 
}