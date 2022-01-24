package Entity;

import java.util.ArrayList;

import Stub.*;

public class Scaffale {
	ArrayList<Libro> Libri;
	private int Numero;
	
	public int getNumero() {
		return Numero;
	}
	public void setNumero(int numero) {
		Numero = numero;
	}
	
	public Scaffale(int numero){
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
		boolean trovato = false;
		int i = 0;
		while((i<Libri.size()) && (!trovato)) {		
			if (Libri.get(i).getTitolo().equals(titolo)) {
				trovato = true;
			} 
			else {
				i++;
			}
		}
		
		if (trovato) {
			return Libri.get(i).getPosizione();
		} 
		else {
			return 0;
		}
	}
}
