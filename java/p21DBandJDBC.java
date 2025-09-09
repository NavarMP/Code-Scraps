public class p21DBandJDBC {
    import java.sql.*; 
import java.io.*; 
public class Prgm21 
{ 
public static void main(String args[]) 
{ 
Connection con=null; 
try 
{ 
 
con=DriverManager.getConnection("jdbc:derby://localhost:1527/Emp","Sa 
bna","123456"); 
Statement st=con.createStatement(); 
ResultSet rs=st.executeQuery("Select * from Employee"); 
System.out.println("------------Employee Details --------------- "); 
System.out.println("\n"); 
System.out.print("Eno "); 
System.out.print("Name "); 
System.out.print("Designation    "); 
System.out.print("Department   "); 
System.out.println(" ---------------------------------------------- "); 
while(rs.next()) 
{ 
System.out.print(rs.getInt("id")); 
System.out.print(" "); 
System.out.print(rs.getString("name")); 
System.out.print(" "); 
System.out.print(rs.getString("design")); 
System.out.print("  "); 
System.out.println(rs.getString("dept")); 
}
}