package Entity;

import Stub.*;

public class Utente {
	private String User;
	private String Password;
	
	public String getUser() {
		return User;
	}
	public void setUser(String user) {
		User = user;
	}
	public String getPassword() {
		return Password;
	}
	public void setPassword(String password) {
		Password = password;
	}
	
	public Utente(int numero){
		StubUtente U = new StubUtente (numero);
		this.User = U.getUser();
		this.Password = U.getPassword();
	}
	
}
