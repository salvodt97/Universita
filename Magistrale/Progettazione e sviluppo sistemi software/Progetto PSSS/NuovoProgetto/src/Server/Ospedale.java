package Server;

import java.util.*;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

public class Ospedale {

	public ArrayList<Paziente> Pazienti;
	ArrayList<Medico> Medici;
	ArrayList<Infermiere> Infermieri;

	
	public ArrayList<String> accesso(String user, String pass) {
		
		ArrayList<String> ritorno=new ArrayList<String>();
		DaoOspedale osp= new DaoOspedale();
		ArrayList<Object> oggetti=osp.caricaUtenti();
		ArrayList<Utente> utenti=new ArrayList<Utente>();
		for(int i=0;i<oggetti.size();i++) {
			DaoUtente u1=new DaoUtente();
			u1=(DaoUtente)oggetti.get(i);
			Utente u=new Utente();
			u.setNome(u1.getNome());
			u.setCognome(u1.getCognome());
			u.setPassword(u1.getPassword());
			u.setUsername(u1.getUsername());
			u.setQualifica(u1.getQualifica());
			utenti.add(u);
		}
		
		
		for(int i=0;i<utenti.size();i++) {
		
			if(utenti.get(i).getUsername().equals(user) && utenti.get(i).getPassword().equals(pass)) {
				ritorno.add(utenti.get(i).getNome());
				ritorno.add(utenti.get(i).getCognome());
				ritorno.add(utenti.get(i).getQualifica());
				ritorno.add(utenti.get(i).getUsername());
				ritorno.add(utenti.get(i).getPassword());
				
			}
		
		}
		
		return ritorno;
		
		
	}
	
	public int creaCartellaClinica(String Nome,String Cognome,String Data_di_nascita,String luogo_di_nascita,
			String recapito,String Codice_fiscale,String principio_attivo,String posologia,String dosaggio,
			String Motivo_ricovero,String Indirizzo ,String anamnesi,String numero_documento,String tipo_documento,ArrayList<String> info, String data_inizio,String data_fine) {
		
		Paziente paziente1=new Paziente(Nome,Cognome,Data_di_nascita,luogo_di_nascita,recapito,Codice_fiscale.toUpperCase(),principio_attivo,posologia,
				dosaggio,Motivo_ricovero,Indirizzo,anamnesi,numero_documento,tipo_documento,info,data_inizio,data_fine);
		
		int codice_cartella=paziente1.salvapaziente(principio_attivo,posologia,
				dosaggio,Motivo_ricovero,Indirizzo,anamnesi,numero_documento,tipo_documento,info,data_inizio,data_fine);
		
		
		
		return codice_cartella;
		
	}
	
	public void aggiornaCartellaClinica(String Nome,String Cognome,String Data_di_nascita,String luogo_di_nascita,
			String recapito,String Codice_fiscale,String principio_attivo,String posologia,String dosaggio,
			String Motivo_ricovero,String Indirizzo ,String anamnesi,String numero_documento,String tipo_documento,ArrayList<String> info, String data_inizio,String data_fine,boolean valore,String codice_ricerca) {
		
		Paziente paziente=new Paziente(Nome,Cognome,Data_di_nascita,luogo_di_nascita,recapito,Codice_fiscale.toUpperCase(),principio_attivo,posologia,
				dosaggio,Motivo_ricovero,Indirizzo,anamnesi,numero_documento,tipo_documento,info,data_inizio,data_fine,valore);
		
		paziente.aggiornapaziente(principio_attivo,posologia,
				dosaggio,Motivo_ricovero,Indirizzo,anamnesi,numero_documento,tipo_documento,info,data_inizio,data_fine,valore,codice_ricerca);
		
		
		
		
		
	}
	
	public String [][] cercaCartellaClinica(String codice_fiscale){
		
		Paziente paziente=new Paziente(codice_fiscale);
		return paziente.cercaCartellaClinica();
		
		
	}

}
