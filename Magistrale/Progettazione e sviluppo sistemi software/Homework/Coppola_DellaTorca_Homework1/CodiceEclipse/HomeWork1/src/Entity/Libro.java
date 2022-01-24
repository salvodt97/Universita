package Entity;

import java.util.ArrayList;
import Stub.*;

public class Libro {
	private String Titolo;
	private int Pagine;
	private int Posizione;
	public ArrayList<Copia> copieLibro;
	
	public String getTitolo() {
		return Titolo;
	}
	public void setTitolo(String titolo) {
		Titolo = titolo;
	}
	public int getPagine() {
		return Pagine;
	}
	public void setPagine(int pagine) {
		Pagine = pagine;
	}
	public int getPosizione() {
		return Posizione;
	}
	public void setPosizione(int posizione) {
		Posizione = posizione;
	}
	
	public Libro(int numeroLibro){
		
		if(numeroLibro==1) {
			StubLibro s = new StubLibro(1);
			Titolo=s.getTitolo();
			Pagine=s.getPagine();
			Posizione=s.getPosizione();
			this.copieLibro = new ArrayList<Copia>();
			for(int i=0; i<s.getCopie().size(); i++) {
				Copia c = new Copia();
				c.setTitoloLibro(s.getCopie().get(i).getTitoloLibro());
				c.setCodice(s.getCopie().get(i).getCodice());
				c.setDisp(s.getCopie().get(i).isDisp());
				for(int j = 0; j<s.getCopie().get(i).getPrestiti().size(); j++) {
					Prestito p = new Prestito(s.getCopie().get(i).getPrestiti().get(j).getDataPrestito(), s.getCopie().get(i).getPrestiti().get(j).getUtente());
					c.getPrestiti().add(p);
				}
				this.copieLibro.add(c);
			}
			
		}
		
		
		if(numeroLibro==2) {
			StubLibro s = new StubLibro(2);
			Titolo=s.getTitolo();
			Pagine=s.getPagine();
			Posizione=s.getPosizione();
			this.copieLibro = new ArrayList<Copia>();
			for(int i=0; i<s.getCopie().size(); i++) {
				Copia c = new Copia();
				c.setTitoloLibro(s.getCopie().get(i).getTitoloLibro());
				c.setCodice(s.getCopie().get(i).getCodice());
				c.setDisp(s.getCopie().get(i).isDisp());
				for(int j = 0; j<s.getCopie().get(i).getPrestiti().size(); j++) {
					Prestito p = new Prestito(s.getCopie().get(i).getPrestiti().get(j).getDataPrestito(), s.getCopie().get(i).getPrestiti().get(j).getUtente());
					c.getPrestiti().add(p);
				}
				this.copieLibro.add(c);
			}
		}
		
		
		if(numeroLibro==3) {
			StubLibro s = new StubLibro(3);
			Titolo=s.getTitolo();
			Pagine=s.getPagine();
			Posizione=s.getPosizione();
			this.copieLibro = new ArrayList<Copia>();
			for(int i=0; i<s.getCopie().size(); i++) {
				Copia c = new Copia();
				c.setTitoloLibro(s.getCopie().get(i).getTitoloLibro());
				c.setCodice(s.getCopie().get(i).getCodice());
				c.setDisp(s.getCopie().get(i).isDisp());
				for(int j = 0; j<s.getCopie().get(i).getPrestiti().size(); j++) {
					Prestito p = new Prestito(s.getCopie().get(i).getPrestiti().get(j).getDataPrestito(), s.getCopie().get(i).getPrestiti().get(j).getUtente());
					c.getPrestiti().add(p);
				}
				this.copieLibro.add(c);
			}
		}
		
		
		if(numeroLibro==4) {
			StubLibro s = new StubLibro(4);
			Titolo=s.getTitolo();
			Pagine=s.getPagine();
			Posizione=s.getPosizione();
			this.copieLibro = new ArrayList<Copia>();
			for(int i=0; i<s.getCopie().size(); i++) {
				Copia c = new Copia();
				c.setTitoloLibro(s.getCopie().get(i).getTitoloLibro());
				c.setCodice(s.getCopie().get(i).getCodice());
				c.setDisp(s.getCopie().get(i).isDisp());
				for(int j = 0; j<s.getCopie().get(i).getPrestiti().size(); j++) {
					Prestito p = new Prestito(s.getCopie().get(i).getPrestiti().get(j).getDataPrestito(), s.getCopie().get(i).getPrestiti().get(j).getUtente());
					c.getPrestiti().add(p);
				}
				this.copieLibro.add(c);
			}
		}
		
		
	}
	
	public Libro() {
		this.copieLibro = new ArrayList<Copia>();
		this.Pagine = 0;
		this.Posizione = 0;
		this.Titolo = "";
	}
	
}
