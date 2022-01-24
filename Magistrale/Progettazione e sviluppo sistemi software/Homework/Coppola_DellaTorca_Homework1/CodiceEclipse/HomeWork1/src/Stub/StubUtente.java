package Stub;

public class StubUtente {
	
	private String User;
	private String Password;
	
	
	public StubUtente(int numero) {
		if(numero == 1) {
			this.User = "vincenzo";
			this.Password = "coppola";
		}
		if(numero == 2) {
			this.User = "salvatore";
			this.Password = "dellatorca";
		}
		if(numero == 3) {
			this.User = "domenico";
			this.Password = "benfenati";
		}
		if(numero == 4) {
			this.User = "salvatore";
			this.Password = "esposito";
		}
		if(numero == 5) {
			this.User = "simona";
			this.Password = "devivo";
		}
		if(numero == 6) {
			this.User = "giacomo";
			this.Password = "prova1";
		}
		if(numero == 7) {
			this.User = "francesco";
			this.Password = "prova2";
		}
		if(numero == 8) {
			this.User = "federico";
			this.Password = "prova3";
		}
		if(numero == 9) {
			this.User = "gennaro";
			this.Password = "prova4";
		}
		if(numero == 10) {
			this.User = "francesca4";
			this.Password = "prova10";
		}
		if(numero == 11) {
			this.User = "cristina56";
			this.Password = "prova11";
		}
		if(numero == 12) {
			this.User = "ernesto12";
			this.Password = "prova12";
		}
		if(numero == 13) {
			this.User = "chiara5";
			this.Password = "prova13";
		}
		if(numero == 14) {
			this.User = "lorenzo41";
			this.Password = "prova14";
		}
		if(numero == 15) {
			this.User = "maria6";
			this.Password = "prova15";
		}
	}
	
	public String getUser() {
		return User;
	}
	public void setUser(String user) {
		this.User = user;
	}
	public String getPassword() {
		return Password;
	}
	public void setPassword(String password) {
		this.Password = password;
	}
	
	
}
