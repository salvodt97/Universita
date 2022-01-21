package Control;
import Entity.Entityofficina;

public class Controllerresponsabile {
	public static String visualizza_richieste(String targa) {
	Entityofficina o=new Entityofficina();
	o.carica_dati();
	if(o.conta_richieste(targa)>0) {
		return "Le richieste di riparazione per la targa " + targa + " sono " + o.conta_richieste(targa)+ " fatte dal cliente "+o.guarda_cliente(targa);
	}
	else return "Non ci sono richieste per l'auto la cui targa è "+targa;
	}
	
	}