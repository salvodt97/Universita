package Client;

import Server.*;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.Window;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.JButton;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.jar.JarException;
import java.net.URL;
import javax.swing.*;

import javax.swing.JPasswordField;


public class LoginUI  {
	
	private JFrame frame;
	private JPanel contentPane;
	private JLabel Username;
	private JLabel Password;
	private JButton login;
	private JTextField campo_user;
	private JPasswordField campo_pass;
	
	/**
	 * Launch the application.
	 **/
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					LoginUI window = new LoginUI();
					window.frame.setVisible(true);
				}catch(Exception e) {
					e.printStackTrace();

				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	
	
	
	public LoginUI() {
		frame =new JFrame();
		frame.setResizable(false);
		try {
			UIManager.setLookAndFeel("javax.swing.plaf.nimbus.NimbusLookAndFeel");
		} catch (ClassNotFoundException e1) {
			
			e1.printStackTrace();
		} catch (InstantiationException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (IllegalAccessException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (UnsupportedLookAndFeelException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		frame.setTitle("Login");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		frame.setContentPane(contentPane);
		contentPane.setLayout(null);
		
		Username = new JLabel("Username");
		Username.setBounds(36, 31, 137, 16);
		contentPane.add(Username);
		
		campo_user = new JTextField();
		campo_user.setBounds(210, 28, 116, 25);
		contentPane.add(campo_user);
		campo_user.setColumns(10);
		
		Password = new JLabel("Password");
		Password.setBounds(36, 82, 71, 16);
		contentPane.add(Password);
		
	
		login = new JButton("Login");
		login.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				
				ArrayList<String> response=new ArrayList<String>();
				String user=campo_user.getText();
				@SuppressWarnings("deprecation")
				String pass=campo_pass.getText();
				
				
				
				DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
				Calendar cal = Calendar.getInstance();
				System.out.println(dateFormat.format(cal.getTime()));
				
		        try {
		            Registry registry = LocateRegistry.getRegistry();
		            metodi stub = (metodi) registry.lookup("facade");
		             response = stub.login(user, pass);
		             
				        if(response.get(2).equals("medico")) {
				        	frame.dispose();
				        	UIFunzioniMedico finestra=new UIFunzioniMedico(response);
				        	finestra.setVisible(true);
				        	
				        }else if(response.get(2).equals("infermiere")){
				        	frame.dispose();
				        	UIVisualizzazione finestra=new UIVisualizzazione(response);
				        	finestra.setVisible(true);
				        	
				        }		      
		            
		        } catch (Exception ex) {
		            System.err.println("Client exception: " + ex.toString());
		            JOptionPane.showMessageDialog(null,"Credenziali errate");
		            ex.printStackTrace();
		        }				
				
			}
		});
		login.setBounds(222, 143, 97, 25);
		contentPane.add(login);
		
		campo_pass = new JPasswordField();
		campo_pass.setBounds(210, 79, 116, 25);
		contentPane.add(campo_pass);
		
		
		
		
	}

	public void setVisible(boolean b) {
		frame.setVisible(b);
		
	}
}
