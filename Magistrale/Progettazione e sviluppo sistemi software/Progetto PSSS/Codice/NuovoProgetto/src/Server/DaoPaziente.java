package Server;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.*;

import javax.persistence.*;

import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;
@Entity
public class DaoPaziente {

	@OneToMany(mappedBy="Dao_Paziente",fetch = FetchType.EAGER,cascade = CascadeType.ALL, orphanRemoval = true)
	//@OneToMany(fetch = FetchType.EAGER,cascade = CascadeType.ALL)
	//@JoinColumn(name="Paziente_codice_fiscale")
	List<DaoCartellaClinica> Dao_CartelleCliniche=new ArrayList<DaoCartellaClinica>();
	
	
	
	@Column
	String nome;
	@Column
	String cognome;
	@Column
	String data_nascita;
	@Id
	String codice_fiscale;
	@Column
	String numero_documento;
	@Column
	String tipo_documento;
	@Column
	String indirizzo;
	@Column
	String luogo_di_nascita;
	@Column
	String recapito_telefonico;
	
	//@ManyToOne(fetch = FetchType.EAGER,cascade = CascadeType.ALL)
	//@JoinColumn(name="DaoOspedale_Nome")
	//DaoOspedale Ospedale;
	
	
	
		public DaoPaziente(String nome,String cognome,String data_nascita,String luogo_di_nascita,
				String recapito,String codice_fiscale,String principio_attivo,String posologia,String dosaggio,
				String Motivo_ricovero,String indirizzo ,String anamnesi,String numero_documento,String tipo_documento,ArrayList<String> info,String data_inizio,String data_fine) {
			
			DaoCartellaClinica cartellaClinica=new DaoCartellaClinica(this,Motivo_ricovero,anamnesi,info,posologia,dosaggio,principio_attivo,data_inizio,data_fine);
			
			Dao_CartelleCliniche.add(cartellaClinica);
		this.nome = nome;
		this.cognome = cognome;
		this.data_nascita = data_nascita;
		this.numero_documento = numero_documento;
		this.codice_fiscale=codice_fiscale;
		this.tipo_documento = tipo_documento;
		this.indirizzo = indirizzo;
		this.luogo_di_nascita = luogo_di_nascita;
		this.recapito_telefonico = recapito;
		
		
		
	}
		
		public DaoPaziente(String nome,String cognome,String data_nascita,String luogo_di_nascita,
				String recapito,String codice_fiscale,String principio_attivo,String posologia,String dosaggio,
				String Motivo_ricovero,String indirizzo ,String anamnesi,String numero_documento,String tipo_documento,String data_inizio,ArrayList<String> info,String data_fine,boolean valore) {
			
			DaoCartellaClinica cartellaClinica=new DaoCartellaClinica(Motivo_ricovero,this,anamnesi,info,posologia,dosaggio,principio_attivo,data_inizio,data_fine,valore);
			
			Dao_CartelleCliniche.add(cartellaClinica);
		this.nome = nome;
		this.cognome = cognome;
		this.data_nascita = data_nascita;
		this.numero_documento = numero_documento;
		this.codice_fiscale=codice_fiscale;
		this.tipo_documento = tipo_documento;
		this.indirizzo = indirizzo;
		this.luogo_di_nascita = luogo_di_nascita;
		this.recapito_telefonico = recapito;
		
		
		
	}
		
	public void salva() {
		Configuration con= new Configuration();
		con.configure("hibernate.cfg.xml");
		@SuppressWarnings("deprecation")
		SessionFactory sf=con.buildSessionFactory();
		Session session=sf.openSession();
		session.beginTransaction();
		
		session.saveOrUpdate(this);
		session.getTransaction().commit();
		session.clear();
		session.close();
		
		
	}
	
	public void aggiornapaziente(String principio_attivo,String posologia,String dosaggio,String codice_ricerca,String anamnesi,boolean attiva) {
		//Le seguenti istruzioni servono ad accedere al Database
		Configuration con= new Configuration();						//Innanzitutto creo una nuova configurazione
		con.configure("hibernate.cfg.xml");
		
		@SuppressWarnings("deprecation")
		SessionFactory sf=con.buildSessionFactory();
		Session session=sf.openSession();							//Apro poi la sessione all'interno della quale inserisco le operazioni da effettuare nel database
		session.beginTransaction();
		
		DaoPaziente paziente=(DaoPaziente)session.get(DaoPaziente.class,codice_ricerca);	//Prelevo dal database il giusto paziente
		
		DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
		Calendar cal = Calendar.getInstance();
		if(!(dosaggio.equals("") || posologia.equals("") || principio_attivo.equals(""))) {
		//Controllo per vedere se il medico ha inserito una terapia
		DaoTerapia nuovaterapia=new DaoTerapia(dosaggio,posologia,principio_attivo,dateFormat.format(cal.getTime()),"");
		paziente.Dao_CartelleCliniche.get(paziente.Dao_CartelleCliniche.size()-1).DaoTerapie.add(nuovaterapia);
		}
		paziente.codice_fiscale=this.codice_fiscale;
		paziente.cognome=this.cognome;
		paziente.data_nascita=this.data_nascita;
		paziente.indirizzo=this.indirizzo;
		paziente.nome=this.nome;
		paziente.luogo_di_nascita=this.luogo_di_nascita;
		paziente.numero_documento=this.numero_documento;
		paziente.tipo_documento=this.tipo_documento;
		paziente.Dao_CartelleCliniche.get(paziente.Dao_CartelleCliniche.size()-1).anamnesi=anamnesi;
		paziente.Dao_CartelleCliniche.get(paziente.Dao_CartelleCliniche.size()-1).stato=attiva;
	
		session.flush();
		session.getTransaction().commit();														//Faccio il commit delle operazioni
		session.clear();
		session.close();																		//Pulisco e chiudo la sessione
		
		
		
		}
	


	public DaoPaziente(String codice_fiscale) {
		super();
		this.codice_fiscale = codice_fiscale;
	}

	public DaoPaziente() {
		super();
	}
	
	
	
	public Object cercaCartellaClinica(String codice_fiscale){
		
		ArrayList<String> ritorno=new ArrayList<String>(); 
		Configuration con= new Configuration();
		con.configure("hibernate.cfg.xml");
		@SuppressWarnings("deprecation")
		SessionFactory sf=con.buildSessionFactory();
		Session session=sf.openSession();
		session.beginTransaction();
	
		Object paziente_esistente=session.get(DaoPaziente.class,codice_fiscale);
		session.getTransaction().commit();
		
		session.clear();
		session.close();
		
	
			return paziente_esistente;
		
		
	}
	}
