package Control;

import Entity.*;

import Entity.Scaffale;

public class BibliotecarioController {

	static public int cercaLibroInScaffale(String Titolo, int NumScaffale) {
		 Biblioteca bib = new Biblioteca();
		 Scaffale scaffale;
		 scaffale = bib.cercaScaffale(NumScaffale);
		 if (scaffale==null) {
			 return 0;
		 } else {
			 return scaffale.ricercaLibro(Titolo);
		 }
	}

	
	static public int visualizzaNumPrestiti(String Titolo) {
		Biblioteca b = new Biblioteca();
		int contatore = 0;
		int i=0;
		Libro L = new Libro();
		L = b.cercaLibro(Titolo);
		
		
		while (i<L.copieLibro.size()) {
			if(!L.copieLibro.get(i).isDisp()) {
				contatore++;
			}
			i++;
		}
		
		return contatore;
	}
	
}