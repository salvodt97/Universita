package Server;

//La classe metodi è un'interfaccia che verrà implementata dalla classe facade per poter far cuminacare il Client con il Server da remoto mediante JavaRMI

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.ArrayList;

public interface metodi extends Remote {
    

	ArrayList<String> login(String user, String pass) throws RemoteException;
	
	int creaCartellaClinica(String Nome,String Cognome,String Data_di_nascita,String luogo_di_nascita,
			String recapito,String Codice_fiscale,String principio_attivo,String posologia,String dosaggio,
			String Motivo_ricovero,String Indirizzo ,String anamnesi,String numero_documento,String tipo_documento,ArrayList<String> info) throws RemoteException;
	
	void aggiornaCartellaClinica(String nome,String cognome,String data_nascita,String luogo_nascita,String recapito,String codice_fiscale,String principio_attivo,String posologia,String dosaggio,String motivo_ricovero,String codice_ricerca,String indirizzo,String numero_documento,String tipo_documento,String anamnesi,boolean valore,ArrayList<String> info) throws RemoteException;

	String[][] cercaCartellaClinica(String codice_fiscale,ArrayList<String> info) throws RemoteException;
		
}
	



	  

