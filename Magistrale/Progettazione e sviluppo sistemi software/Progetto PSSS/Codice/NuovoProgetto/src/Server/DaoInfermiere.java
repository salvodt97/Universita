package Server;

import javax.persistence.*;

@Entity
public class DaoInfermiere {

	@Column
	String nome;
	@Column
	String cognome;
	@Id
	String username;
	@Column
	String password;
	
	//@ManyToOne(fetch = FetchType.EAGER)
	//@JoinColumn(name="Infermiere_visualizzazione")
	//DaoCartellaClinica cartellaVisualizzata;

}