package Server;

public class Utente {
	
	private String nome;
	private String cognome;
	private String username;
	private String password;
	private String qualifica;
	
	public Utente(String username,String nome, String cognome,String password,String qualifica) {
		this.nome = nome;
		this.cognome = cognome;
		this.username=username;
		this.qualifica=qualifica;
		this.password=password;
	}
	public Utente() {
		super();
	}
	public String getQualifica() {
		return qualifica;
	}
	public void setQualifica(String qualifica) {
		this.qualifica = qualifica;
	}
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
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
}
