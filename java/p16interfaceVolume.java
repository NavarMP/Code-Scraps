public class p17interfaceVolume {
    interface Volume 
{ 
double pi=3.14; 
void readdata(); 
void dispvolume(); 
} 
class Sphere implements Volume 
{ 
int r=0; 
double vs=0; 
public void readdata() 
{ 
r=5; 
} 
public void dispvolume() 
{ 
vs=(4*pi*r*r*r)/3; 
System.out.println(“Volume of the Sphere:” +vs); 
} 
} 
 
class Cylinder extends Sphere 
{ 
int r=0,h=0; 
double v; 
public void readdata() 
{ 
super.readdata(); 
r=6; 
h=4; 
} 
public void dispvolume() 
{ 
super.dispvolume(); 
v=pi*r*r*h; 
System.out.println(“Volume of the Cylinder:” +v); 
} 
} 
public class Vol 
{ 
public static void main(String args[]) 
{ 
Cylinder obj=new Cylinder(); 
obj.readdata(); 
obj.dispvolume(); 
} 
}
}
