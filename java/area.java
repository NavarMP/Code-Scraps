public class area {
    public static void main(String[] args) {
        double radius = .70;
        double circleArea = Math.PI * radius * radius;

        System.out.println ("Area of circle=" + circleArea);

        double length = 10.0;
        double width = 5.0;
        double recArea = length * width;

        System.out.println ("Area of rectangle=" + recArea);

        double base = 8.0;
        double height = 4.0;
        double triArea = 0.5 * base * height;

        System.out.println ("Area of triangle=" + triArea);
    }
}
