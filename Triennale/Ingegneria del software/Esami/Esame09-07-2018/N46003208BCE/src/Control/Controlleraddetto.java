package Control;
import Entity.Entityesame;
import java.util.ArrayList;

public class Controlleraddetto {
	
	public Controlleraddetto() {
		
	}

	public static String interroga_sistema(String data) {
		
		ArrayList<Entityesame> esami= new ArrayList<Entityesame>();
		esami=Entity.Entityuniversita.interroga_sistema_con_data(data);
		
		
		if(esami.isEmpty()) {
			return "Non ci sono esami per quella data";
		}
		else {
			int b=1;
			for(int j=0; j<esami.size()-1;j++) {
				if(esami.get(j).getEntitycorso().getCodice()!=esami.get(j+1).getEntitycorso().getCodice()) {
					b=b+1;
					}
				else j++;
				}
			return "In data "+ data + " sono stati superati " + esami.size() + " esami in "  +b+ " corsi.";
			
	}
	}


}
