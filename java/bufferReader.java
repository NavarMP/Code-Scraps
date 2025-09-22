import java.io.*;

public class bufferReader {
    public static void main(String[] args) throws IOException {
        // Create BufferedReader object
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Take first number
        System.out.print("Enter first number: ");
        int num1 = Integer.parseInt(br.readLine());

        // Take second number
        System.out.print("Enter second number: ");
        int num2 = Integer.parseInt(br.readLine());

        // Add the numbers
        int sum = num1 + num2;

        // Print result
        System.out.println("Sum = " + num1 + " + " + num2 + " = " + sum);
    }
}