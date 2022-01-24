package Entity;

import java.util.ArrayList;
import Stub.*;


public class Copia {
	
	private String titoloLibro;
	private String codice;
	private ArrayList<Prestito> prestiti = new ArrayList<Prestito>();
	private boolean disp;
	
	public Copia(String titolo, String cod, boolean d, int scelta) {
		titoloLibro = titolo;
		codice = cod;
		disp = d;
		if(scelta == 1) {
			StubPrestito StP = new StubPrestito(1);
			StubPrestito StP1 = new StubPrestito(4);
			Prestito s = new Prestito(StP.getDataPrestito(), StP.getUtente());
			Prestito s1 = new Prestito(StP1.getDataPrestito(), StP1.getUtente());
			this.prestiti.add(s);
			this.prestiti.add(s1);
		}
		
		if(scelta == 2) {
			StubPrestito StP = new StubPrestito(2);
			StubPrestito StP1 = new StubPrestito(3);
			Prestito s = new Prestito(StP.getDataPrestito(), StP.getUtente());
			Prestito s1 = new Prestito(StP1.getDataPrestito(), StP1.getUtente());
			this.prestiti.add(s);
			this.prestiti.add(s1);
		}
		
		if(scelta == 3) {
			StubPrestito StP = new StubPrestito(3);
			StubPrestito StP1 = new StubPrestito(5);
			Prestito s = new Prestito(StP.getDataPrestito(), StP.getUtente());
			Prestito s1 = new Prestito(StP1.getDataPrestito(), StP1.getUtente());
			this.prestiti.add(s);
			this.prestiti.add(s1);
		}
		
		if(scelta == 4) {
			StubPrestito StP = new StubPrestito(1);
			StubPrestito StP1 = new StubPrestito(2);
			Prestito s = new Prestito(StP.getDataPrestito(), StP.getUtente());
			Prestito s1 = new Prestito(StP1.getDataPrestito(), StP1.getUtente());
			this.prestiti.add(s);
			this.prestiti.add(s1);
		}
	}

	public Copia() {
		this.codice = "";
		this.disp = false;
		this.titoloLibro = "";
	}
	
	
	public String getTitoloLibro() {
		return titoloLibro;
	}

	public void setTitoloLibro(String titoloLibro) {
		this.titoloLibro = titoloLibro;
	}

	public String getCodice() {
		return codice;
	}

	public void setCodice(String codice) {
		this.codice = codice;
	}

	public ArrayList<Prestito> getPrestiti() {
		return prestiti;
	}

	public void setPrestiti(ArrayList<Prestito> prestiti) {
		this.prestiti = prestiti;
	}

	public boolean isDisp() {
		return disp;
	}

	public void setDisp(boolean disp) {
		this.disp = disp;
	}
	
	
	
}
