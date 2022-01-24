package Stub;

import java.util.ArrayList;

public class StubCopia {
	
	private String titoloLibro;
	private String codice;
	private ArrayList<StubPrestito> prestiti;
	private boolean disp;
		
	
	public StubCopia(String titoloLibro,  int scegli) {
		this.titoloLibro = titoloLibro;
		if(scegli == 1) {
			this.codice = "AF134685";
			this.disp = false;
			StubPrestito p1 = new StubPrestito(1);
			StubPrestito p2 = new StubPrestito(2);
			this.prestiti = new ArrayList<StubPrestito>();
			this.prestiti.add(p1);
			this.prestiti.add(p2);
		}
		
		if(scegli == 2) {
			this.codice = "AK167946";
			this.disp = true;
			StubPrestito p1 = new StubPrestito(2);
			StubPrestito p2 = new StubPrestito(3);
			this.prestiti = new ArrayList<StubPrestito>();
			this.prestiti.add(p1);
			this.prestiti.add(p2);
		}
		
		if(scegli == 3) {
			this.codice = "DM164973";
			this.disp = true;
			StubPrestito p1 = new StubPrestito(3);
			StubPrestito p2 = new StubPrestito(4);
			this.prestiti = new ArrayList<StubPrestito>();
			this.prestiti.add(p1);
			this.prestiti.add(p2);
		}
		
		if(scegli == 4) {
			this.codice = "LH167349";
			this.disp = false;
			StubPrestito p1 = new StubPrestito(4);
			StubPrestito p2 = new StubPrestito(5);
			this.prestiti = new ArrayList<StubPrestito>();
			this.prestiti.add(p1);
			this.prestiti.add(p2);
		}
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
	public ArrayList<StubPrestito> getPrestiti() {
		return prestiti;
	}
	public void setPrestiti(ArrayList<StubPrestito> prestiti) {
		this.prestiti = prestiti;
	}
	public boolean isDisp() {
		return disp;
	}
	public void setDisp(boolean disp) {
		this.disp = disp;
	}

}
