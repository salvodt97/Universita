package Database;

import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DBExample {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Class.forName("com.mysql.jdbc.Driver");
			java.sql.Connection conn= DriverManager.getConnection("jdbc:mysql://localhost:3306/bibliotecaIS?autoReconnect=true&useSSL=false", "yourUserName", "yourPassword");
			Statement stmt=conn.createStatement();
			String query="SELECT * FROM TabLibri";
			ResultSet rs=stmt.executeQuery(query);
			while(rs.next()){
				System.out.print("Titolo "+rs.getString("Titolo"));
				System.out.print(" Pagine "+rs.getString("PPagine"));
				System.out.println(" Posizione "+rs.getString("Posizione"));
			}
		} catch (ClassNotFoundException | SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}

}
