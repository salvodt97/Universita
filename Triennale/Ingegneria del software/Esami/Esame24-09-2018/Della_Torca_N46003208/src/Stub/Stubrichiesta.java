package Stub;

public class Stubrichiesta {
	
	Stubautomobile stubautomobile;
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
	public Stubrichiesta(int id, String da, String mo, String ma, String ta, int imm, String no, String co, int ce) {
		identificativo=id;
		data=da;
		stubautomobile=new Stubautomobile(mo,ma,ta,imm,no,co,ce);	
	}
	}
