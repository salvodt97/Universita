package Control;

import Entity.*;

public class UtenteController {

	public static boolean ricercaCopieDisponibili(String aTitolo) {
		Biblioteca B = new Biblioteca();
		Libro L = B.cercaLibro(aTitolo);
		boolean disp = false;
		int i = 0;
		while(i<L.copieLibro.size() && !disp) {
			if(L.copieLibro.get(i).isDisp()) {
				disp = true;
			}
			i++;
		}
		return disp;
	}

	public static boolean Login(String aUser, String aPsw) {
		Biblioteca bib = new Biblioteca();
		boolean temp = bib.LoginBib(aUser, aPsw);
		return temp;
	}
}