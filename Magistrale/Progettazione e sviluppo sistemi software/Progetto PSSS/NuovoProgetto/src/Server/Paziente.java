package Server;

import java.util.*;

import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;
public class Paziente {

	private ArrayList<CartellaClinica> CartelleCliniche=new ArrayList<CartellaClinica>();
	private String nome;
	private String cognome;
	private String data_nascita;
	private String codice_fiscale;
	private int codice_numerico;
	private String numero_documento;
	private String tipo_documeno;
	private String indirizzo;
	private String luogo_di_nascita;
	private String recapito_telefonico;
	
	public Paziente(String nome,String cognome,String data_nascita,String luogo_di_nascita,
			String recapito,String codice_fiscale,String principio_attivo,String posologia,String dosaggio,
			String Motivo_ricovero,String Indirizzo ,String anamnesi,String numero_documento,String tipo_documento,ArrayList<String>info,String data_inizio,String data_fine) {
		CartellaClinica cartellaClinica=new CartellaClinica(Motivo_ricovero,anamnesi,info,posologia,dosaggio,principio_attivo,data_inizio,data_fine);
		CartelleCliniche.add(cartellaClinica);
		this.nome = nome;
		this.cognome = cognome;
		this.data_nascita = data_nascita;
		this.codice_fiscale = codice_fiscale;
		this.numero_documento = numero_documento;
		this.tipo_documeno = tipo_documento;
		this.indirizzo = Indirizzo;
		this.luogo_di_nascita = luogo_di_nascita;
		this.recapito_telefonico = recapito;
	}
	public Paziente(String nome,String cognome,String data_nascita,String luogo_di_nascita,
			String recapito,String codice_fiscale,String principio_attivo,String posologia,String dosaggio,
			String Motivo_ricovero,String Indirizzo ,String anamnesi,String numero_documento,String tipo_documento,ArrayList<String>info,String data_inizio,String data_fine,boolean valore) {
		CartellaClinica cartellaClinica=new CartellaClinica(Motivo_ricovero,anamnesi,info,posologia,dosaggio,principio_attivo,data_inizio,data_fine,valore);
		CartelleCliniche.add(cartellaClinica);
		this.nome = nome;
		this.cognome = cognome;
		this.data_nascita = data_nascita;
		this.codice_fiscale = codice_fiscale;
		this.numero_documento = numero_documento;
		this.tipo_documeno = tipo_documento;
		this.indirizzo = Indirizzo;
		this.luogo_di_nascita = luogo_di_nascita;
		this.recapito_telefonico = recapito;
	}
	public ArrayList<CartellaClinica> getCartelleCliniche() {
		return CartelleCliniche;
	}
	public void setCartelleCliniche(ArrayList<CartellaClinica> cartelleCliniche) {
		CartelleCliniche = cartelleCliniche;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public String getCognome() {
		return cognome;
	}
	public void setCognome(String cognome) {
		this.cognome = cognome;
	}
	public String getData_nascita() {
		return data_nascita;
	}
	public void setData_nascita(String data_nascita) {
		this.data_nascita = data_nascita;
	}
	public String getCodice_fiscale() {
		return codice_fiscale;
	}
	public void setCodice_fiscale(String codice_fiscale) {
		this.codice_fiscale = codice_fiscale;
	}
	public int getCodice_numerico() {
		return codice_numerico;
	}
	public void setCodice_numerico(int codice_numerico) {
		this.codice_numerico = codice_numerico;
	}
	public String getNumero_documento() {
		return numero_documento;
	}
	public void setNumero_documento(String numero_documento) {
		this.numero_documento = numero_documento;
	}
	public String getTipo_documeno() {
		return tipo_documeno;
	}
	public void setTipo_documeno(String tipo_documeno) {
		this.tipo_documeno = tipo_documeno;
	}
	public String getIndirizzo() {
		return indirizzo;
	}
	public void setIndirizzo(String indirizzo) {
		this.indirizzo = indirizzo;
	}
	public String getLuogo_di_nascita() {
		return luogo_di_nascita;
	}
	public void setLuogo_di_nascita(String luogo_di_nascita) {
		this.luogo_di_nascita = luogo_di_nascita;
	}
	public String getRecapito_telefonico() {
		return recapito_telefonico;
	}
	public void setRecapito_telefonico(String recapito_telefonico) {
		this.recapito_telefonico = recapito_telefonico;
	}
	
	public int salvapaziente(String principio_attivo,String posologia,String dosaggio,
			String Motivo_ricovero,String Indirizzo ,String anamnesi,String numero_documento,String tipo_documento,ArrayList<String> info,String data_inizio,String data_fine){
		
		DaoPaziente pazientedasalvare=new DaoPaziente(this.nome,this.cognome,this.data_nascita,this.luogo_di_nascita,this.recapito_telefonico,this.codice_fiscale,principio_attivo,posologia,dosaggio,Motivo_ricovero,indirizzo,anamnesi,numero_documento,tipo_documento,info,data_inizio,data_fine);
		
		
		//aggiungee due parametri codice fiscale e username
		pazientedasalvare.salva();
		
		
		
		return pazientedasalvare.Dao_CartelleCliniche.get(pazientedasalvare.Dao_CartelleCliniche.size()-1).IDCartella;
		
	}
	
	public void aggiornapaziente(String principio_attivo,String posologia,String dosaggio,
			String Motivo_ricovero,String Indirizzo ,String anamnesi,String numero_documento,String tipo_documento,ArrayList<String> info,String data_inizio,String data_fine,boolean valore,String codice_ricerca){
		
		DaoPaziente pazientedaaggiornare=new DaoPaziente(this.nome,this.cognome,this.data_nascita,this.luogo_di_nascita,this.recapito_telefonico,this.codice_fiscale,principio_attivo,posologia,dosaggio,Motivo_ricovero,indirizzo,anamnesi,numero_documento,tipo_documento,data_inizio,info,data_fine,valore);
				
		pazientedaaggiornare.aggiornapaziente(principio_attivo,dosaggio,posologia,codice_ricerca,anamnesi,valore);
	}
	
public String[][] cercaCartellaClinica(){
	
	 	
	
		DaoPaziente pazientedacaricare=new DaoPaziente(this.codice_fiscale);
		
		DaoPaziente p=(DaoPaziente)pazientedacaricare.cercaCartellaClinica(this.codice_fiscale);
		if(p!=null) {
		
		String [][] t=new String[1+p.Dao_CartelleCliniche.get(p.Dao_CartelleCliniche.size()-1).DaoTerapie.size()][13];
		
			
			
			t[0][0]=p.nome;
			t[0][1]=p.cognome;
			t[0][2]=p.codice_fiscale;
			t[0][3]=p.data_nascita;
			t[0][4]=p.indirizzo;
			t[0][5]=p.luogo_di_nascita;
			t[0][6]=p.numero_documento;
			t[0][7]=p.tipo_documento;
			t[0][8]=p.recapito_telefonico;
			t[0][9]=p.Dao_CartelleCliniche.get(p.Dao_CartelleCliniche.size()-1).anamnesi;
			t[0][10]=p.Dao_CartelleCliniche.get(p.Dao_CartelleCliniche.size()-1).data_ricovero;
			t[0][11]=Integer.toString(p.Dao_CartelleCliniche.get(p.Dao_CartelleCliniche.size()-1).IDCartella);
			t[0][12]=p.Dao_CartelleCliniche.get(p.Dao_CartelleCliniche.size()-1).motivo_ricovero;
			for(int i=0;i<p.Dao_CartelleCliniche.get(p.Dao_CartelleCliniche.size()-1).DaoTerapie.size();i++) {
				
				t[1+i][0]=p.Dao_CartelleCliniche.get(p.Dao_CartelleCliniche.size()-1).DaoTerapie.get(i).principio_attivo;
				t[1+i][1]=p.Dao_CartelleCliniche.get(p.Dao_CartelleCliniche.size()-1).DaoTerapie.get(i).posologia;
				t[1+i][2]=p.Dao_CartelleCliniche.get(p.Dao_CartelleCliniche.size()-1).DaoTerapie.get(i).dosaggio;
				t[1+i][3]=p.Dao_CartelleCliniche.get(p.Dao_CartelleCliniche.size()-1).DaoTerapie.get(i).data_inizio;
				t[1+i][4]=p.Dao_CartelleCliniche.get(p.Dao_CartelleCliniche.size()-1).DaoTerapie.get(i).data_fine;
			}
			
			
			return t;
	
			
	
		}else {
			String [][] z = new String [1][1];
			return z;
		}
			
		
		
}



public Paziente(String codice_fiscale) {
	super();
	this.codice_fiscale = codice_fiscale;
}
	
	

}