package Stub;

import Stub.StubCorso;

public class StubEsame {

	StubCorso stubcorso;
	private String data;
	private int voto;
	private boolean lode;
	

	public String getData() {
		return data;
	}
	public void setData(String data) {
		this.data = data;
	}
	public int getVoto() {
		return voto;
	}
	public void setVoto(int voto) {
		this.voto = voto;
	}
	public boolean isLode() {
		return lode;
	}
	public void setLode(boolean lode) {
		this.lode = lode;
	}

	
	public StubEsame(String d, int v, boolean l, int co, String no){
		data = d;
		voto=v;
		lode=l;
		stubcorso=new StubCorso(co,no);			
	}
	
	
}