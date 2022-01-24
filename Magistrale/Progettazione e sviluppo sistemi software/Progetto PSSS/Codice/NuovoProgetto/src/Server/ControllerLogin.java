package Server;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;

public class  ControllerLogin {
		

	
	public static ArrayList<String> login(String user, String pass) {
		
		Ospedale ospedale=new Ospedale();
		return ospedale.accesso(user, pass);
		
		
	}

	
	
}
