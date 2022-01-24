package Stub;

import java.util.ArrayList;

public class StubScaffale {
	public ArrayList<StubLibro> Libri;
	private int Numero;
	
	public int getNumero() {
		return Numero;
	}
	public void setNumero(int numero) {
		Numero = numero;
	}
	
	public StubScaffale(int numero){
		if(numero==1) {
			this.Numero=1;
			Libri = new ArrayList<StubLibro>();
			StubLibro SL1=new StubLibro(1);
			StubLibro SL2=new StubLibro(2);
			this.Libri.add(SL1);
			this.Libri.add(SL2);
		}
		if(numero==2) {
			this.Numero=2;
			Libri = new ArrayList<StubLibro>();
			StubLibro SL1=new StubLibro(3);
			StubLibro SL2=new StubLibro(4);
			this.Libri.add(SL1);
			this.Libri.add(SL2);
		}
	}
	
}
