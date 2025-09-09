public class p13countNoOfObjects {
    static int count=0;
    p13countNoOfObjects() {
        count++;
    }
    public static void main(String args[]) {
    p13countNoOfObjects obj1=new p13countNoOfObjects();
    p13countNoOfObjects obj2=new p13countNoOfObjects();
    p13countNoOfObjects obj3=new p13countNoOfObjects();
    p13countNoOfObjects obj4=new p13countNoOfObjects();
    System.out.println("Number of Objects Created: " + count);
    }
}