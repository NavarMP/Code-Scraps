import java.sql.*;

public class p21DBandJDBC {
    public static void main(String args[]) {
        Connection con = null;
        Statement st = null;
        ResultSet rs = null;
        try {
            con = DriverManager.getConnection("jdbc:derby://localhost:1527/Emp", "Sabna", "123456");
            st = con.createStatement();
            rs = st.executeQuery("Select * from Employee");
            System.out.println("------------Employee Details --------------- ");
            System.out.println();
            System.out.print("Eno ");
            System.out.print("Name ");
            System.out.print("Designation    ");
            System.out.print("Department   ");
            System.out.println(" ---------------------------------------------- ");
            while (rs.next()) {
                System.out.print(rs.getInt("id"));
                System.out.print(" ");
                System.out.print(rs.getString("name"));
                System.out.print(" ");
                System.out.print(rs.getString("design"));
                System.out.print("  ");
                System.out.println(rs.getString("dept"));
            }
            System.in.read(); // Wait for user input before closing
        } catch (Exception e) {
            System.out.println(e.getMessage());
        } finally {
            try { if (rs != null) rs.close(); } catch (Exception e) {}
            try { if (st != null) st.close(); } catch (Exception e) {}
            try { if (con != null) con.close(); } catch (Exception e) {}
        }
    }
}