import java.util.Scanner;

public class add2No {
    public static void main(String[] args) {
        System.out.println("Addition");

        Scanner scanner = new Scanner(System.in);

        System.out.println ("Enter first number: ");
        String num1 = scanner.nextLine();

        System.out.println ("Enter second number: ");
        String num2 = scanner.nextLine();

        System.out.println (num1 + "+" + num2 + "=" + (Integer.parseInt(num1) + Integer.parseInt(num2)));
    }
}