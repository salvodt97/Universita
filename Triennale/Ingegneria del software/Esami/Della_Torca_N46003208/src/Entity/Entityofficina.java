package Entity;
import Entity.Entityrichiesta;

import java.util.ArrayList;

public class Entityofficina {

		ArrayList<Entityrichiesta> entityrichieste;
		private String nome;
		
		public String getNome() {
			return nome;
		}
		
		public void carica_dati() {
			entityrichieste=new ArrayList<Entityrichiesta>();
			Entityrichiesta r1=new Entityrichiesta(1,"24-09-2016", "Fiat", "500", "RO-342-NA", 2013, "Salvatore", "Della Torca", 341124142);
			Entityrichiesta r2=new Entityrichiesta(2,"24-09-2017", "Fiat", "500", "RO-342-NA", 2013, "Salvatore", "Della Torca", 341124142);
			Entityrichiesta r3=new Entityrichiesta(3,"24-09-2018", "Fiat", "500", "RO-342-NA", 2013, "Salvatore", "Della Torca", 341124142);
			Entityrichiesta r4=new Entityrichiesta(4,"11-03-2004", "Audi", "A4", "BO-253-MI", 2000, "Giuseppe", "Della Torca", 301527192);
			entityrichieste.add(r1);
			entityrichieste.add(r2);
			entityrichieste.add(r3);
			entityrichieste.add(r4);
		}
		
		public int conta_richieste(String targa) {
			int j=0;
			for(int i=0;i<entityrichieste.size();i++) {
				if(entityrichieste.get(i).entityautomobile.getTarga().equals(targa))
					j++;
			}	
			return j;
		}
		
		public String guarda_cliente(String targa) {
			String a="Errore";
			for(int i=0; i<entityrichieste.size(); i++) {
				if(entityrichieste.get(i).entityautomobile.getTarga().equals(targa)) {
					a= entityrichieste.get(i).guarda_nome();
				}	
		}
			return a;
	}
		
		public Entityofficina() {
			
		}
}