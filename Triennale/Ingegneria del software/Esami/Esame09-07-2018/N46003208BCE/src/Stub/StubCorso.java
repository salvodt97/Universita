package Stub;

public class StubCorso {
	private int codice;
	private String nome;
	
	public int getCodice() {
		return codice;
	}
	public void setCodice(int codice) {
		this.codice = codice;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	
	public StubCorso(int co, String no){
		codice=co;
		nome=no;
	}
	

}
