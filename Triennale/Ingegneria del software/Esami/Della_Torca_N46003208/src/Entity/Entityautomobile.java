package Entity;
import Stub.Stubautomobile;

public class Entityautomobile {
	
	Entitycliente entitycliente;
	private String targa;
	private String modello;
	private String marca;
	private int immatricolazione;
	
	public String getTarga() {
		return targa;
	}
	public void setTarga(String targa) {
		this.targa = targa;
	}
	public String getModello() {
		return modello;
	}
	public void setModello(String modello) {
		this.modello = modello;
	}
	public String getMarca() {
		return marca;
	}
	public void setMarca(String marca) {
		this.marca = marca;
	}
	public int getImmatricolazione() {
		return immatricolazione;
	}
	public void setImmatricolazione(int immatricolazione) {
		this.immatricolazione = immatricolazione;
	}
	
	public String guarda_cliente() {
		return entitycliente.getNome() + " " + entitycliente.getCognome() + ".";
	}
	
	public Entityautomobile(String mo, String ma, String ta, int imm, String no, String co, int ce) {
	    Stubautomobile a=new Stubautomobile(mo,ma,ta,imm,no,co,ce);
	    modello=a.getModello();
	    marca=a.getMarca();
	    targa=a.getTarga();
	    immatricolazione=a.getImmatricolazione();
	    entitycliente=new Entitycliente(no,co,ce);
	}

}
