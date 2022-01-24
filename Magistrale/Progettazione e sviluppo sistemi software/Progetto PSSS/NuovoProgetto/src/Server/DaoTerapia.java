package Server;

import javax.persistence.*;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;


@Entity
public class DaoTerapia {

	public DaoTerapia() {
		super();
	}

	@Column
	String dosaggio;
	
	@Column
	String posologia;
	
	@Column
	String data_inizio;
	
	@Column
	String data_fine;
	
	@Column
	String principio_attivo;
	
	@Id
	@GeneratedValue
	int IDTerapia;
	
	@ManyToOne
	@JoinColumn(name="IDCartellaClinica")
	DaoCartellaClinica cartella_clinica;

	public DaoTerapia(String dosaggio, String posologia, String principio_attivo, String data_inizio, String data_fine) {
		this.dosaggio = dosaggio;
		this.posologia = posologia;
		this.data_inizio = data_inizio;
		this.data_fine = data_fine;
		this.principio_attivo = principio_attivo;
		
	}

	

	public void salvaTerapia(Session session) {
		
		
		session.save(this);
	
	}
	public String getDosaggio() {
		return dosaggio;
	}

	public void setDosaggio(String dosaggio) {
		this.dosaggio = dosaggio;
	}

	public String getPosologia() {
		return posologia;
	}

	public void setPosologia(String posologia) {
		this.posologia = posologia;
	}

	public String getData_inizio() {
		return data_inizio;
	}

	public void setData_inizio(String data_inizio) {
		this.data_inizio = data_inizio;
	}

	public String getData_fine() {
		return data_fine;
	}

	public void setData_fine(String data_fine) {
		this.data_fine = data_fine;
	}

	public String getPrincipio_attivo() {
		return principio_attivo;
	}

	public void setPrincipio_attivo(String principio_attivo) {
		this.principio_attivo = principio_attivo;
	}

	public int getId() {
		return IDTerapia;
	}

	public void setId(int id) {
		this.IDTerapia = id;
	}
	
	

}