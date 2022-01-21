package Entity;
import Stub.Stubrichiesta;

public class Entityrichiesta {
	
	Entityautomobile entityautomobile;
	private int identificativo;
	private String data;
	
	public int getIdentificativo() {
		return identificativo;
	}
	public void setIdentificativo(int identificativo) {
		this.identificativo = identificativo;
	}
	public String getData() {
		return data;
	}
	public void setData(String data) {
		this.data = data;
	}
	
	public String guarda_auto() {
		return entityautomobile.getTarga();
	}
	
	public String guarda_nome() {
		return entityautomobile.guarda_cliente();
	}
	
	public Entityrichiesta(int id, String da, String mo, String ma, String ta, int imm, String no, String co, int ce) {
		Stubrichiesta s=new Stubrichiesta(id,da,mo,ma,ta,imm,no,co,ce);
		identificativo=s.getIdentificativo();
		data=s.getData();
		entityautomobile=new Entityautomobile(mo,ma,ta,imm,no,co,ce);
		
		
	}
}
