import java.util.*; 
class Account { 
    int accno, balance = 0, wd; 
    Scanner sc; 
    Account() { 
        sc = new Scanner(System.in); 
    } 
    void deposit() { 
        System.out.println("Enter Amount to deposit:"); 
        int amount = sc.nextInt(); 
        balance = balance + amount; 
    } 
    void getbalance() { 
        System.out.println("Balance=" + balance); 
    } 
    void withDraw() { 
        System.out.println("Enter Amount to withdraw:"); 
        wd = sc.nextInt(); 
        try { 
            if (balance < wd) 
            throw new MinBalExp(); 
            System.out.println("Collect amount"); 
        } catch (Exception e) { 
            System.out.println(e); 
        } 
    } 
} 
 
class MinBalExp extends Exception { 
    MinBalExp() { 
        System.out.println("Sorry, Your account has that much balance"); 
    } 
} 

public class p18BankAc {
    public static void main(String args[]) { 
        Account a = new Account(); 
        a.deposit(); 
        a.withDraw(); 
    } 
}
