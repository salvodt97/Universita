package Entity;
import Stub.StubCorso;
public class Entitycorso {

	private int codice;
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
	private String nome;

	public Entitycorso(int co, String no) {
		StubCorso c=new StubCorso(co,no);
		codice=c.getCodice();
		nome=c.getNome();
	}
	
}