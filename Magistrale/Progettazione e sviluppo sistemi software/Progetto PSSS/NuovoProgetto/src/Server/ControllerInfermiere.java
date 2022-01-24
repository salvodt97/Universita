package Server;

import java.util.ArrayList;

public class ControllerInfermiere {
	
public static String [][] cercaCartellaClinica(String codice_fiscale,ArrayList<String> info){
		
		Ospedale ospedale=new Ospedale();
		 return ospedale.cercaCartellaClinica(codice_fiscale);
		 
		 
		 
		 
	}
}