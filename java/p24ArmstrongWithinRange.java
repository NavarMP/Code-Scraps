public class p24ArmstrongWithinRange {
    import java.util.Scanner; 
 
public class ArmstrongNumbersInRange { 
    // Function to check Armstrong number 
    public static boolean isArmstrong(int num) { 
        int original = num, sum = 0, digits = 0; 
        // Count digits 
        int temp = num; 
        while (temp > 0) { 
            digits++; 
            temp /= 10; 
        } 
        // Calculate sum of powers 
        temp = num; 
        while (temp > 0) { 
            int digit = temp % 10; 
            sum += Math.pow(digit, digits); 
            temp /= 10; 
        } 
 
        return sum == original; 
    } 
 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
 
        // Input range 
        System.out.print("Enter the starting number: "); 
        int start = sc.nextInt(); 
        System.out.print("Enter the ending number: "); 
        int end = sc.nextInt(); 
 
System.out.println("Armstrong numbers between " + start + " and " 
 + end + " are:"); 
        for (int i = start; i <= end; i++) { 
            if (isArmstrong(i)) { 
                System.out.print(i + " "); 
            } 
        } 
 
        sc.close(); 
    } 
}
}
