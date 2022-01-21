package Entity;
import Stub.Stubcliente;

public class Entitycliente {
	
	private String nome;
	private String cognome;
	private int cellulare;
	
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
	public int getCellulare() {
		return cellulare;
	}
	public void setCellulare(int cellulare) {
		this.cellulare = cellulare;
	}
	
	public Entitycliente(String no, String co, int ce) {
		Stubcliente c=new Stubcliente(no,co,ce);
		nome=c.getNome();
		cognome=c.getCognome();
		cellulare=c.getCellulare();
	}

}
