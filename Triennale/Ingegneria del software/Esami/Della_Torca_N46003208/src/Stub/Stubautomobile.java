package Stub;

public class Stubautomobile {
	
	Stubcliente stubcliente;
	private String modello;
	private String marca;
	private int immatricolazione;
	private String targa;
	
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
	
	public Stubautomobile (String mo, String ma, String ta, int imm, String no, String co, int ce) {
    modello=mo;
    marca=ma;
    targa=ta;
    immatricolazione=imm;
    stubcliente=new Stubcliente(no, co, ce);
	}
}


