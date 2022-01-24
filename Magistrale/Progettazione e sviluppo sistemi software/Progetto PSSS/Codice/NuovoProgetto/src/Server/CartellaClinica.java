package Server;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.*;

public class CartellaClinica {

	
	//private ArrayList<Infermiere> Infermieri;
	private Medico Medico_creatore;
	private ArrayList<Medico> Medici_aggiornatori;
	private ArrayList<Terapia> Terapie;
	//private ArrayList<Referto> Referti;
	//private ArrayList<Medico> Medici_visualizzatori;
	private int IDCartella;
	private boolean stato;
	private String motivo_ricovero;
	private String anamnesi;
	private String data_ricovero;
	
	
	public CartellaClinica(String motivo_ricovero, String anamnesi, ArrayList<String> info,String posologia,String dosaggio,String principio_attivo,String data_inizio,String data_fine) {
		
		this.Medico_creatore=new Medico(info);
		this.stato = true;
		this.motivo_ricovero = motivo_ricovero;
		this.anamnesi = anamnesi;
		Terapia terapia= new Terapia(dosaggio,posologia,principio_attivo,data_inizio,data_fine);
		this.Terapie=new ArrayList<Terapia>();
		this.Terapie.add(terapia);
		DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
		Calendar cal = Calendar.getInstance();
		this.data_ricovero = dateFormat.format(cal.getTime());
	}
	
	public CartellaClinica(String motivo_ricovero, String anamnesi, ArrayList<String> info,String posologia,String dosaggio,String principio_attivo,String data_inizio,String data_fine,boolean valore) {
		
		
		this.stato = true;
		this.motivo_ricovero = motivo_ricovero;
		this.anamnesi = anamnesi;
		Terapia terapia= new Terapia(dosaggio,posologia,principio_attivo,data_inizio,data_fine);
		this.Terapie=new ArrayList<Terapia>();
		this.Terapie.add(terapia);
		DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
		Calendar cal = Calendar.getInstance();
		this.data_ricovero = dateFormat.format(cal.getTime());
		this.stato=valore;
	}

	public int getIDCartella() {
		return IDCartella;
	}

	public void setIDCartella(int iDCartella) {
		IDCartella = iDCartella;
	}

	public boolean isStato() {
		return stato;
	}

	public void setStato(boolean stato) {
		this.stato = stato;
	}

	public String getMotivo_ricovero() {
		return motivo_ricovero;
	}

	public void setMotivo_ricovero(String motivo_ricovero) {
		this.motivo_ricovero = motivo_ricovero;
	}

	public String getAnamnesi() {
		return anamnesi;
	}

	public void setAnamnesi(String anamnesi) {
		this.anamnesi = anamnesi;
	}

	public String getData_ricovero() {
		return data_ricovero;
	}

	public void setData_ricovero(String data_ricovero) {
		this.data_ricovero = data_ricovero;
	}

}