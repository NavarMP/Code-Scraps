public class p13countNoOfObjects {
    public class NumObj 
{ 
static int count=0; 
NumObj() 
{ 
count++; 
} 
public static void main(String args[]) 
{ 
NumObj obj1=new NumObj(); 
NumObj obj2=new NumObj(); 
NumObj obj3=new NumObj(); 
NumObj obj4=new NumObj(); 
System.out.println(“Number of Objetcs Created” + count); 
} 
}
}
