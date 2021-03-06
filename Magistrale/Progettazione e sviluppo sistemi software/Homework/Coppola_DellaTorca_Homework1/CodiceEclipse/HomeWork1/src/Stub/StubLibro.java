package Stub;

import java.util.ArrayList;


public class StubLibro {

	private String Titolo;
	private int Pagine;
	private int Posizione;
	private ArrayList<StubCopia> copie;
	
	public String getTitolo() {
		return Titolo;
	}
	public void setTitolo(String titolo) {
		Titolo = titolo;
	}
	public int getPagine() {
		return Pagine;
	}
	public void setPagine(int pagine) {
		Pagine = pagine;
	}
	public int getPosizione() {
		return Posizione;
	}
	public void setPosizione(int posizione) {
		Posizione = posizione;
	}
	public ArrayList<StubCopia> getCopie() {
		return copie;
	}
	public void setCopie(ArrayList<StubCopia> copie) {
		this.copie = copie;
	}
	
	
	public StubLibro(int n) {
		
		if(n==1) {
			Titolo = "Harry Potter";
			Pagine = 184;
			Posizione = 1;
			StubCopia c1 = new StubCopia(Titolo, 1);
			StubCopia c2 = new StubCopia(Titolo, 2);
			this.copie = new ArrayList<StubCopia>();
			this.copie.add(c1);
			this.copie.add(c2);
		}
		
		if(n==2) {
			Titolo = "Il signore degli anelli";
			Pagine = 189;
			Posizione = 2;
			StubCopia c1 = new StubCopia(Titolo, 3);
			StubCopia c2 = new StubCopia(Titolo, 4);
			this.copie = new ArrayList<StubCopia>();
			this.copie.add(c1);
			this.copie.add(c2);
		}
		
		if(n==3) {
			Titolo = "IT";
			Pagine = 267;
			Posizione = 3;
			StubCopia c1 = new StubCopia(Titolo, 1);
			StubCopia c2 = new StubCopia(Titolo, 4);
			this.copie = new ArrayList<StubCopia>();
			this.copie.add(c1);
			this.copie.add(c2);
		}
		
		if(n==4) {
			Titolo = "Odissea";
			Pagine = 308;
			Posizione = 4;
			StubCopia c1 = new StubCopia(Titolo, 2);
			StubCopia c2 = new StubCopia(Titolo, 3);
			this.copie = new ArrayList<StubCopia>();
			this.copie.add(c1);
			this.copie.add(c2);
		}
	}
	
	
}
