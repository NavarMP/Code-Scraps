import java.util.Scanner; 
abstract class Shape { 
    final float pi = 3.14f; 
    abstract void area(); 
} 
class TwoDim { 
    Scanner sc; 
    TwoDim() {
        sc = new Scanner(System.in); 
    }
    void area() {}
}
class ThreeDim extends Shape {
    int a;
    Scanner sc;
    ThreeDim() {
        sc = new Scanner(System.in);
    }
    void area() {
    }
}

class Square extends TwoDim {
    float area;
    int a;
    Square() {
        super();
        a = 0;
        area = 0.0f;
    }
    void read() {
        System.out.println("Enter side of a square: ");
        a = sc.nextInt();
    }
    void area() {
        area = a * a;
        System.out.println("Area of Square= " + area);
    }
}
class Triangle extends TwoDim {
    float area;
    int b;
    int h;
    Triangle() {
        super(); 
        b = 0;
        h = 0;
        area = 0.0f;
    }
    void read() {
        System.out.println("Enter breadth of a triangle: ");
        b = sc.nextInt();
        System.out.println("Enter height of a triangle: ");
        h = sc.nextInt();
    }
    void area() {
        area = (b * h) / 2;
        System.out.println("Area of Triangle= " + area);
    }
}
class Sphere extends ThreeDim {
    float area;
    int r;
    Sphere() {
        super();
        r = 0;
        area = 0.0f;
    }
    void read() {
        System.out.println("Enter radius of sphere: ");
        r = sc.nextInt();
    }
    void area() {
        area = (4 * pi * r * r);
        System.out.println("Area of Sphere= " + area);
    }
}

class Cube extends ThreeDim {
    float area;
    int a;
    Cube() {
        super();
        a = 0;
        area = 0.0f;
    }
    void read() {
        System.out.println("Enter side of cube: ");
        a = sc.nextInt();
    }
    void area() {
        area = 6 * a * a;
        System.out.println("Area of Cube= " + area);
    }
} 
 
public class p15abstractClassShape { 
public static void main(String args[]) 
{ 
Square s = new Square(); 
Triangle t = new Triangle(); 
Sphere sp = new Sphere(); 
Cube c = new Cube(); 
s.read(); 
sp.read(); 
t.read(); 
c.read(); 
s.area(); 
t.area(); 
sp.area(); 
c.area(); 
} 
}