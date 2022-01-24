package Stub;


public class StubPrestito {
	
	private int dataPrestito;
	private String utente;
		
	
	public StubPrestito(int scelta) {
		if(scelta == 1) {
			
			this.dataPrestito = 150514;
			this.utente = "vincenzo34";
		}
		
		if(scelta == 2) {
			
			this.dataPrestito = 180416;
			this.utente = "antonio2";
		}
		
		if(scelta == 3) {
			
			this.dataPrestito = 180214;
			this.utente = "raffaela47";
		}
		
		if(scelta == 4) {
			
			this.dataPrestito = 161013;
			this.utente = "maria34";
		}
		
		if(scelta == 5) {
			
			this.dataPrestito = 130513;
			this.utente = "marco64";
		}
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
