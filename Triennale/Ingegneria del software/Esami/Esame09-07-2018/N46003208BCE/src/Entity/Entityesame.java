package Entity;
import Stub.StubEsame;

public class Entityesame {

	private String data;
	private int voto;
	private boolean lode;
	Entitycorso entitycorso;
	
	public Entitycorso getEntitycorso() {
		return entitycorso;
	}
	public void setEntitycorso(Entitycorso entitycorso) {
		this.entitycorso = entitycorso;
	}

	
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
	
	public Entityesame(String d, int v, boolean l, int co, String no) {
		StubEsame e= new StubEsame(d,v,l,co,no);
		this.data=e.getData();
		this.voto=e.getVoto();
		this.lode=e.isLode();
		entitycorso=new Entitycorso(co,no);
	
	}


}
