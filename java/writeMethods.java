import java.io.*;

public class writeMethods {
    public static void main(String[] args) throws Exception {
        String fileName = "numbers.txt";

        // Step 1: Write two numbers into the file
        FileWriter fw = new FileWriter(fileName);
        fw.write("25\n");
        fw.write("15\n");
        fw.close();

        // Step 2: Read numbers from the file
        BufferedReader br = new BufferedReader(new FileReader(fileName));
        int num1 = Integer.parseInt(br.readLine().trim());
        int num2 = Integer.parseInt(br.readLine().trim());
        br.close();

        // Step 3: Add the numbers
        int sum = num1 + num2;

        // Step 4: Write the result back to the same file (append mode)
        fw = new FileWriter(fileName, true); // append = true
        fw.write("Sum = " + sum + "\n");
        fw.close();

        // display finished message
        System.out.print ("File Updated");

        // Step 5: Read the entire file and display contents
        // br = new BufferedReader(new FileReader(fileName));
        // System.out.println("File content after writing result:\n");
        // String line;
        // while ((line = br.readLine()) != null) {
        //     System.out.println(line); 
        // }
        // br.close();
    }
}