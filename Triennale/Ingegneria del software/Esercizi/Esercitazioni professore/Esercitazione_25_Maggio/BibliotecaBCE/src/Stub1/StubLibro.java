package Stub1;

import java.util.ArrayList;

public class StubLibro {
	private String Titolo;
	private int Pagine;
	private int Posizione;
	
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
	
	StubLibro(String tit, int pag, int pos){
		this.setTitolo(tit);
		this.setPagine(pag);
		this.setPosizione(pos);
	}
	
	
}
