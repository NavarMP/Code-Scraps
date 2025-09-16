interface Volume { 
    double pi=3.14; 
    void readdata(); 
    void dispvolume(); 
} 
class Sphere implements Volume {
    int rad=0; 
    double sphereVol=0; 
    public void readdata() { 
        rad=5; 
    } 
    public void dispvolume() { 
        sphereVol=(4*pi*rad*rad*rad)/3; 
        System.out.println("Volume of the Sphere:" + sphereVol); 
    }
} 
 
class Cylinder extends Sphere { 
    int rad=0,height=0; 
    double vol; 
    public void readdata() {
        super.readdata(); 
        rad=6; 
        height=4; 
    } 
    public void dispvolume() { 
        super.dispvolume(); 
        vol=pi * rad * rad * height; 
        System.out.println("Volume of the Cylinder: " + vol); 
    } 
} 
public class p17interfaceVolume { 
    public static void main(String args[]) { 
        Cylinder obj=new Cylinder(); 
        obj.readdata(); 
        obj.dispvolume(); 
    } 
}
