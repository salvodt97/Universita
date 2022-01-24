package Server;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;

public class ControllerMedico {
	

	public static int creaCartellaClinica(String Nome,String Cognome,String Data_di_nascita,String luogo_di_nascita,
			String recapito,String Codice_fiscale,String principio_attivo,String posologia,String dosaggio,
			String Motivo_ricovero,String Indirizzo ,String anamnesi,String numero_documento,String tipo_documento,ArrayList<String> info) {
		DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
		Calendar cal = Calendar.getInstance();
		Ospedale ospedale=new Ospedale();
		return ospedale.creaCartellaClinica(Nome, Cognome, Data_di_nascita, luogo_di_nascita, recapito, Codice_fiscale, principio_attivo, posologia, dosaggio, Motivo_ricovero, Indirizzo, anamnesi,numero_documento,tipo_documento,info,dateFormat.format(cal.getTime()),"");
		
		
	}
	
	public static void  aggiornaCartellaClinica(String nome,String cognome,String data_nascita,String luogo_nascita,String recapito,String codice_fiscale,String principio_attivo,String posologia,String dosaggio,String motivo_ricovero,String codice_ricerca,String indirizzo,String numero_documento,String tipo_documento,String anamnesi,boolean valore,ArrayList<String> info){
		
		DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
		Calendar cal = Calendar.getInstance();
		Ospedale ospedale=new Ospedale();
		 ospedale.aggiornaCartellaClinica(nome, cognome, data_nascita, luogo_nascita, recapito, codice_fiscale,  principio_attivo,posologia, dosaggio, motivo_ricovero, indirizzo, anamnesi, numero_documento,tipo_documento, info,dateFormat.format(cal.getTime()),"" ,valore,codice_ricerca.toUpperCase());
	}
	
	
	
}
