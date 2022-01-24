package Server;

//La classe facade implementa le funzioni dell'interfaccia metodi; inoltre funziona come Design Pattern facade, ovvero contiene i metodi dei 3 controller
//così il Client non conosce come è fatto l'Application Layer, ma vede solo il facade
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;

import javax.swing.JOptionPane;

public class facade implements metodi {

	
	@Override
	public ArrayList<String> login(String user, String pass) {
		
		return ControllerLogin.login(user, pass);
			
	}
	
	@Override
	public int creaCartellaClinica(String Nome,String Cognome,String Data_di_nascita,String luogo_di_nascita,
			String recapito,String Codice_fiscale,String principio_attivo,String posologia,String dosaggio,
			String Motivo_ricovero,String Indirizzo ,String anamnesi,String numero_documento,String tipo_documento,ArrayList<String> info) {
		return ControllerMedico.creaCartellaClinica(Nome, Cognome, Data_di_nascita, luogo_di_nascita, recapito, Codice_fiscale, principio_attivo, posologia, dosaggio, Motivo_ricovero, Indirizzo, anamnesi, numero_documento, tipo_documento, info);
				
	}
	
	@Override
	public void aggiornaCartellaClinica(String nome,String cognome,String data_nascita,String luogo_nascita,String recapito,String codice_fiscale,String principio_attivo,String posologia,String dosaggio,String motivo_ricovero,String codice_ricerca,String indirizzo,String numero_documento,String tipo_documento,String anamnesi,boolean valore,ArrayList<String> info){
		
			
		 ControllerMedico.aggiornaCartellaClinica(nome,cognome,data_nascita,luogo_nascita,recapito,codice_fiscale,principio_attivo,posologia,dosaggio,motivo_ricovero,codice_ricerca,indirizzo,numero_documento,tipo_documento,anamnesi,valore,info);
	}
	
	
	@Override
	public  String [][] cercaCartellaClinica(String codice_fiscale,ArrayList<String> info){
		
		return ControllerInfermiere.cercaCartellaClinica(codice_fiscale.toUpperCase(),info);
		 
		 
		 
		 
	}
	
	
	 public static void main(String args[]) {
	        //Avvio del server sul porto 1099
	        try {
	            facade obj = new facade();
	            metodi stub = (metodi) UnicastRemoteObject.exportObject(obj, 0);

	            Registry registry = LocateRegistry.createRegistry(1099);
	            registry.bind("facade", stub);

	            System.err.println("Server ready");
	            JOptionPane.showMessageDialog(null,"Server avviato");
	        } catch (Exception e) {
	            System.err.println("Server exception: " + e.toString());
	            e.printStackTrace();
	        }
	    }
	
}
