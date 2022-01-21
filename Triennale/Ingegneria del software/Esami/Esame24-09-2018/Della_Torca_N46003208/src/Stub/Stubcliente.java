package Stub;

public class Stubcliente {
	
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
	
	public Stubcliente(String no, String co, int ce) {
		nome=no;
		cognome=co;
		cellulare=ce;
	}


}
