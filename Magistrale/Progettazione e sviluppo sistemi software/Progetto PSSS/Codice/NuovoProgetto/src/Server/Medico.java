package Server;

import java.util.*;

public class Medico extends Utente {

	ArrayList<RichiestaEsame> Richieste_effettuate;

	public Medico(ArrayList<String> info) {
		super(info.get(3),info.get(0),info.get(1),info.get(4),info.get(2));
	}
	

}