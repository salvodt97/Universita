package Server;

import java.util.Random;

public class Terapia {

	private String dosaggio;
	private String posologia;
	private String data_inizio;
	private String data_fine;
	private String principio_attivo;
	
	public Terapia(String dosaggio, String posologia, String principio_attivo,String data_inizio, String data_fine) {
		this.dosaggio = dosaggio;
		this.posologia = posologia;
		this.data_inizio = data_inizio;
		this.data_fine = data_fine;
		this.principio_attivo = principio_attivo;
		
	}

}