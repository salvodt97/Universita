package Entity;

import java.util.ArrayList;

public class Entityuniversita {

	 static ArrayList<Entityesame> entityesami= new ArrayList<Entityesame>();
	 
	 

	public  static ArrayList<Entityesame> interroga_sistema_con_data(String data){
		Entityesame e=new Entityesame("09/07/2018", 28, false, 12345, "Ingegneria del software");
		Entityesame e1=new Entityesame("09/07/2018", 30, true, 12345, "Ingegneria del software");
		Entityesame e2=new Entityesame("09/07/2018", 27, false, 12345, "Ingegneria del software");
		Entityesame e3=new Entityesame("28/06/2018", 28, false, 34256, "Teoria dei segnali");
		Entityesame e4=new Entityesame("09/07/2018", 30, false, 34256, "Teoria dei segnali");
		Entityesame e5=new Entityesame("28/05/2018", 28, false, 65749, "Fondamenti dei sistemi dinamici");
		entityesami.add(e);
		entityesami.add(e1);
		entityesami.add(e2);
		entityesami.add(e3);
		entityesami.add(e4);
		entityesami.add(e5);
		ArrayList<Entityesame> esamigiusti= new ArrayList<Entityesame>();
		for(int i=0; i<entityesami.size();i++) {
			if(entityesami.get(i).getData().equals(data)) {
				esamigiusti.add(entityesami.get(i));
			}
		}
		return esamigiusti;
	}

}