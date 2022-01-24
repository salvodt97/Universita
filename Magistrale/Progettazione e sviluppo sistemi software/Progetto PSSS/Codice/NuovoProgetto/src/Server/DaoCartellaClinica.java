package Server;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.*;

import javax.persistence.*;

import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.annotations.Where;
import org.hibernate.cfg.Configuration;
@Entity
public class DaoCartellaClinica {

	@ManyToOne
	@JoinColumn(name="Paziente_codice_fiscale")
	DaoPaziente Dao_Paziente;
	
	//@OneToMany(fetch = FetchType.EAGER,cascade = CascadeType.ALL)
	//@JoinColumn(name="Infermiere_visualizzazione")
	//List<DaoUtente> Dao_Infermieri;
	
	@OneToOne(fetch = FetchType.EAGER,cascade = CascadeType.ALL)
	@JoinColumn(name="Utente_creazione")
	DaoUtente Dao_Medico_Creatore;
	
	//@OneToMany(fetch = FetchType.EAGER,cascade = CascadeType.ALL)
	//@JoinColumn(name="Medico_aggiornamento")
	//List<DaoUtente> Dao_Medici_aggiornatori=new ArrayList<DaoUtente>();
	
	@OneToMany(fetch = FetchType.EAGER,cascade = CascadeType.ALL)
	@JoinColumn(name="IDCartellaClinica")
	List<DaoTerapia> DaoTerapie=new ArrayList<DaoTerapia>();
	
//	Set<DaoReferto> DaoReferti;
	
	//@OneToMany(fetch = FetchType.EAGER)
	//@JoinColumn(name="Medico_visualizzazione")
	//Set<DaoUtente> Dao_Medici_visualizzatori;
	
	@Id
	@GeneratedValue
	int IDCartella;
	@Column
	boolean stato;
	@Column
	String motivo_ricovero;
	@Column
	String anamnesi;
	@Column
	String data_ricovero;
	
	public DaoCartellaClinica() {
		super();
	}
	
	public DaoCartellaClinica(int iDCartella, boolean stato, String motivo_ricovero, String anamnesi,
			String data_ricovero) {
		
		this.IDCartella = iDCartella;
		this.stato = stato;
		this.motivo_ricovero = motivo_ricovero;
		this.anamnesi = anamnesi;
		this.data_ricovero = data_ricovero;
	}
	
	public DaoCartellaClinica(String motivo_ricovero,DaoPaziente paziente, String anamnesi, ArrayList<String> info,String posologia,String dosaggio,String principio_attivo,String data_inizio,String data_fine,boolean stato) {
		
		//this.Dao_Medici_aggiornatori.add(new DaoUtente(info.get(3),info.get(0),info.get(1),info.get(2),info.get(4)));
		this.Dao_Paziente=paziente;
		this.motivo_ricovero = motivo_ricovero;
		this.anamnesi = anamnesi;
		DaoTerapia terapia= new DaoTerapia(dosaggio,posologia,principio_attivo,data_inizio,data_fine);
		this.DaoTerapie=new ArrayList<DaoTerapia>();
		this.DaoTerapie.add(terapia);
		this.stato=stato;
		DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
		Calendar cal = Calendar.getInstance();
		this.data_ricovero = dateFormat.format(cal.getTime());
	}
	
	public DaoCartellaClinica(DaoPaziente paziente,String motivo_ricovero, String anamnesi, ArrayList<String> info,String posologia,String dosaggio,String principio_attivo,String data_inizio,String data_fine) {
		this.Dao_Medico_Creatore=new DaoUtente(info.get(3),info.get(0),info.get(1),info.get(2),info.get(4));
		this.Dao_Paziente=paziente;
		this.stato = true;
		this.motivo_ricovero = motivo_ricovero;
		this.anamnesi = anamnesi;
		DaoTerapia terapia= new DaoTerapia(dosaggio,posologia,principio_attivo,data_inizio,data_fine);
		this.DaoTerapie=new ArrayList<DaoTerapia>();
		this.DaoTerapie.add(terapia);
		DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
		Calendar cal = Calendar.getInstance();
		this.data_ricovero = dateFormat.format(cal.getTime());
	}

}