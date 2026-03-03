import java.util.*; 
class Overload {
    double area(float l,float w,float b) {
        return l*w*b;
    }
    double area(float l) { 
        return l*l*l;
    }
    double area(float r,float h) {
        return 3.14*r*r*h;
    }
}
public class p14volumeCalc {
    public static void main(String args[]) { 
        Overload ov=new Overload(); 
        Scanner sc=new Scanner(System.in); 
        System.out.println("Enter the length, width and height of the rectangular box");

        float l=sc.nextInt(); 
        float w=sc.nextInt(); 
        float h=sc.nextInt(); 
        double rect=ov.area(l,w,h); 
        System.out.println("Volume of rectangular box " + rect);

        System.out.println("Enter the edge length of Cube"); 
        float e=sc.nextInt(); 
        double cube=ov.area(e); 
        System.out.println("Volume of Cube is " + cube); 
        System.out.println("Enter the radius and height of the Cylinder");
        float r=sc.nextInt(); 
        float hi=sc.nextInt(); 
        double cyli=ov.area(r,hi); 
        System.out.println("Volume of Cylinder is " + cyli); 
        }
}
