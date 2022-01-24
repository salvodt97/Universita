package Entity;


public class Prestito {
	private int dataPrestito;
	private String utente;
	
	public Prestito(int data, String u){
		this.dataPrestito = data;
		this.utente = u;
	}

	public int getDataPrestito() {
		return dataPrestito;
	}

	public void setDataPrestito(int dataPrestito) {
		this.dataPrestito = dataPrestito;
	}

	public String getUtente() {
		return utente;
	}

	public void setUtente(String utente) {
		this.utente = utente;
	}
}
