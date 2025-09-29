package jdbc;
import java.sql.*;

Class.forName("oracle.jdbc.driver.OracleDriver");

DriverManager.registerDriver(new oracle.jdbc.driver.OracleDriver())

Connection con = DriverManager.getConnection(url,user,password)

String url = “jdbc:mysql://localhost:3306/testdb”