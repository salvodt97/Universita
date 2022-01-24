package Server;

import java.util.ArrayList;

import javax.persistence.*;
import org.hibernate.*;
import org.hibernate.Query;
import org.hibernate.cfg.Configuration;


@Entity
public class DaoUtente {
	
	@Id 
	String username;
	
	@Column
	String password;
	
	@Column
	String nome;
	
	@Column
	String cognome;
	
	@Column
	String qualifica;
	
	//@OneToOne(fetch = FetchType.EAGER)
	//@JoinColumn(name="Utente_creazione")
	//DaoCartellaClinica cartellaCreata;
	
	//@ManyToOne(fetch = FetchType.EAGER)
	//@JoinColumn(name="Medico_aggiornamento")
	//DaoCartellaClinica cartellaModificaMedico;
	
	//@ManyToOne(fetch = FetchType.EAGER)
	//@JoinColumn(name="Medico_visualizzazione")
	//DaoCartellaClinica cartellaAccessoMedico;
	
	//@ManyToOne(fetch = FetchType.EAGER)
	//@JoinColumn(name="Infermiere_visualizzazione")
	//DaoCartellaClinica cartellaVisualizzata;
	
	
	
	
	public String getUsername() {
		return username;
	}

	public DaoUtente(String username, String nome, String cognome, String qualifica,String password) {
	
		this.username=username;
		this.nome = nome;
		this.cognome = cognome;
		this.qualifica = qualifica;
		this.password=password;
	}



	public DaoUtente() {
		
	}

	




	public void setUsername(String username) {
		this.username = username;
	}




	public String getPassword() {
		return password;
	}




	public void setPassword(String password) {
		this.password = password;
	}




	public String getNome() {
		return nome;
	}




	public void setNome(String nome) {
		this.nome = nome;
	}




	public String getCognome() {
		return cognome;
	}




	public void setCognome(String cognome) {
		this.cognome = cognome;
	}




	public String getQualifica() {
		return qualifica;
	}




	public void setQualifica(String qualifica) {
		this.qualifica = qualifica;
	}

}
