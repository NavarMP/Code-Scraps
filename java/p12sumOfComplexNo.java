import java.util.*; 
class Complex { 
    int real,imaginary; 
    Complex() {} 
    Complex(int tempReal,int tempImaginary) { 
        real=tempReal; 
        imaginary=tempImaginary; 
    } 
    Complex addComp(Complex c1,Complex c2) { 
        Complex temp=new Complex(); 
        temp.real=c1.real+c2.real; 
        temp.imaginary=c1.imaginary+c2.imaginary; 
        return temp;
    } 
}
 
public class p12sumOfComplexNo { 
    public static void main(String args[]) {
    Scanner sc=new Scanner(System.in); 
    System.out.println("Enter first real part number");
    int a=sc.nextInt();
    System.out.println("Enter first imaginary part number");
    int b=sc.nextInt();
    Complex c1=new Complex(a,b); 
    System.out.println("Enter second real part number");
    int c=sc.nextInt(); 
    System.out.println("Enter second imaginary part number"); 
    int d=sc.nextInt(); 
    Complex c2=new Complex(c,d); 
    System.out.println("Complex number 1" + c1.real+ "+" + c1.imaginary + "i"); 
    System.out.println("Complex number 2" + c2.real+ "+" + c2.imaginary + "i"); 
    Complex c3=new Complex(); 
    c3=c3.addComp(c1,c2); 
    System.out.println("Sum of Complex Number" + c3.real + "+" +c3.imaginary + “i”);
    } 
} 