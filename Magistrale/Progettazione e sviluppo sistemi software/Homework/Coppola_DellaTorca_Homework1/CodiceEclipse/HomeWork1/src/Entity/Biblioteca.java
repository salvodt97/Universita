package Entity;

import java.util.ArrayList;

public class Biblioteca {
	public ArrayList<Scaffale> Scaffali = new ArrayList<Scaffale>();
	public ArrayList<Utente> Utenti = new ArrayList<Utente>();
	public ArrayList<Libro> Libri = new ArrayList<Libro>();
	
	public Biblioteca() {
		Scaffale scf1 = new Scaffale(1);
		Scaffale scf2 = new Scaffale(2);
		this.Scaffali.add(scf1);
		this.Scaffali.add(scf2);	
		
		//popolamento del vettore degli utenti contenuto nella classe biblioteca
		for(int i = 1; i <= 15; i++) {
			Utente u = new Utente(i);
			this.Utenti.add(u);
		}
		
		//popolamento del vettore dei libri contenuto nella classe biblioteca
		for(int j = 1; j <= 4; j++) {
			Libro L = new Libro(j);
			this.Libri.add(L);
		}
		
}
	
	
	public  Scaffale cercaScaffale(int NumScaffale) {
		int i=0;
		boolean trovato=false;
		while((i<Scaffali.size()) && (!trovato)){
			if (Scaffali.get(i).getNumero() == NumScaffale) {
				trovato=true;
			} else {
				i++;
			}
		}
		if (trovato) {
			return Scaffali.get(i);
		} else {
			return null;
		}
	}
	
	
	public Libro cercaLibro(String titolo) {
		int i = 0;
		boolean trovato = false;
		Libro LVuoto = new Libro();
		while(i<Libri.size() &&  !trovato) {
			if(titolo.equals(Libri.get(i).getTitolo())) {
				trovato = true;
				LVuoto = Libri.get(i);
			}
			else {
				i++;
			}
		}
		return LVuoto;
		
	}
	
	public boolean LoginBib(String username, String psw) {
		int i=0;
		boolean trovato = false;
		
		while((i<this.Utenti.size()) && !trovato) {
			if(username.equals(Utenti.get(i).getUser()) && psw.equals(Utenti.get(i).getPassword())) {
				trovato = true;
			}
			i++;
		}
		return trovato;
		
	}


	public ArrayList<Utente> getUtenti() {
		return Utenti;
	}


	public void setUtenti(ArrayList<Utente> utenti) {
		Utenti = utenti;
	}
	
}

