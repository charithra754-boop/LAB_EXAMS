import java.sql.*;

public class JdbcDemo {
    public static void main(String[] args) {
        System.out.println("--- 🗄️ JDBC Database Demo 🗄️ ---");
        // Fun Fact: SQL was originally called SEQUEL (Structured English Query Language), but the name was changed due to a trademark issue.

        // Database credentials (Mock)
        String url = "jdbc:mysql://localhost:3306/testdb";
        String user = "root";
        String password = "password";

        Connection conn = null;
        Statement stmt = null;

        try {
            // 1. Load Driver
            // Note: This usually requires mysql-connector-java.jar in the classpath
            Class.forName("com.mysql.cj.jdbc.Driver");
            System.out.println("Driver loaded!");

            // 2. Connect
            System.out.println("Connecting to database...");
            conn = DriverManager.getConnection(url, user, password);
            System.out.println("Connected!");

            // 3. Create Statement
            stmt = conn.createStatement();

            // 4. Create Table
            String sqlCreate = "CREATE TABLE IF NOT EXISTS Students (id INT PRIMARY KEY, name VARCHAR(50), age INT)";
            stmt.execute(sqlCreate);
            System.out.println("Table 'Students' created.");

            // 5. Insert
            String sqlInsert = "INSERT INTO Students VALUES (101, 'Alice', 20)";
            int rows = stmt.executeUpdate(sqlInsert);
            System.out.println("Inserted " + rows + " row(s).");

            // 6. Display
            String sqlSelect = "SELECT * FROM Students";
            ResultSet rs = stmt.executeQuery(sqlSelect);
            
            System.out.println("\n--- Database Records ---");
            while(rs.next()) {
                System.out.println("ID: " + rs.getInt("id") + ", Name: " + rs.getString("name") + ", Age: " + rs.getInt("age"));
            }

        } catch (ClassNotFoundException e) {
            System.out.println("\n[Error] JDBC Driver not found!");
            System.out.println("To run this, you need the MySQL Connector JAR in your classpath.");
            System.out.println("Example command: java -cp .:mysql-connector.jar JdbcDemo");
        } catch (SQLException e) {
            System.out.println("\n[Error] Database Connection Failed!");
            System.out.println("Ensure MySQL is running and credentials are correct.");
            System.out.println("Error details: " + e.getMessage());
        } finally {
            try {
                if(stmt != null) stmt.close();
                if(conn != null) conn.close();
            } catch(SQLException se) {
                se.printStackTrace();
            }
        }
    }
}
