package Server;

import java.util.ArrayList;
import javax.persistence.*;
import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

@Entity	
public class DaoOspedale {

	@Id
	int ID;
	
	
public ArrayList<Object> caricaUtenti() {
		
		
		ArrayList<Object> utenti=new ArrayList<Object>();
		
		Configuration con= new Configuration();
		con.configure("hibernate.cfg.xml");
		@SuppressWarnings("deprecation")
		SessionFactory sf=con.buildSessionFactory();
		Session session=sf.openSession();
		session.beginTransaction();
		Query query=session.createQuery("SELECT s FROM DaoUtente s ");
		
		utenti=(ArrayList<Object>)query.list();
		session.getTransaction().commit();
		session.close();	
		
		return utenti;
		
	}

public Object caricaUtenteLoggato(String username){
	
	Configuration con= new Configuration();
	con.configure("hibernate.cfg.xml");
	@SuppressWarnings("deprecation")
	SessionFactory sf=con.buildSessionFactory();
	Session session=sf.openSession();
	session.beginTransaction();
	
	Object utente=session.get(DaoUtente.class, username);
	
	session.getTransaction().commit();
	
	session.clear();
	session.close();
	
	return utente;
}


public DaoOspedale(int iD) {
	super();
	ID = iD;
}

public DaoOspedale() {
	super();
	
}
}
