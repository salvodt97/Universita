package Entity1;

import java.util.ArrayList;

import Stub1.StubScaffale;

public class Scaffale {
	ArrayList<Libro> Libri;
	private int Numero;
	
	public int getNumero() {
		return Numero;
	}
	public void setNumero(int numero) {
		Numero = numero;
	}
	
	Scaffale(int numero){
		//equivale a select su DB
		StubScaffale StS= new StubScaffale(numero);
		
		this.Numero=StS.getNumero();
		Libri = new ArrayList<Libro>();
		
		for (int i=0; i<StS.Libri.size();i++){
			Libro L = new Libro();
			L.setTitolo(StS.Libri.get(i).getTitolo());
			L.setPagine(StS.Libri.get(i).getPagine());
			L.setPosizione(StS.Libri.get(i).getPosizione());	
			Libri.add(L);
		}
	}
	
	public int ricercaLibro(String titolo){
		int posizione =0;
		for (int i=0; i<Libri.size(); i++){
			if (Libri.get(i).getTitolo().equals(titolo)) {
				posizione = Libri.get(i).getPosizione();
			}
		}
		return posizione;
	}
}
