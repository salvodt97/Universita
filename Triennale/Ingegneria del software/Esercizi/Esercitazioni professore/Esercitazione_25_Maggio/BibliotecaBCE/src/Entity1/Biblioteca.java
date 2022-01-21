package Entity1;

import java.util.ArrayList;

public class Biblioteca {
	static ArrayList<Scaffale> Scaffali = new ArrayList<Scaffale>();
	
	public static int cercaLibro(String Titolo, int NumScaffale){
		Scaffale Scf = new Scaffale(NumScaffale);
		Scaffali.add(Scf);
		return Scf.ricercaLibro(Titolo);
	}
}
