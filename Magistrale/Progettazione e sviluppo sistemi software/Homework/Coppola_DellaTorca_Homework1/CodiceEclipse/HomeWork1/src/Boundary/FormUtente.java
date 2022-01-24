package Boundary;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JPasswordField;
import javax.swing.JButton;
import javax.swing.JToggleButton;
import javax.swing.JCheckBox;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class FormUtente extends JFrame {

	private JPanel contentPane;
	private JTextField textFieldNomeUtente;
	private JPasswordField passwordFieldPassUtente;
	private JCheckBox chckbxVediPassword;


	/**
	 * Create the frame.
	 */
	public FormUtente() {
		setTitle("Interfaccia Utente");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		chckbxVediPassword = new JCheckBox("Vedi password");
		chckbxVediPassword.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(chckbxVediPassword.isSelected()) {
					passwordFieldPassUtente.setEchoChar((char)0);
				}
				else {
					passwordFieldPassUtente.setEchoChar('*');
				}
			}
		});
		chckbxVediPassword.setBounds(310, 78, 118, 23);
		contentPane.add(chckbxVediPassword);
		
		JLabel lblNomeUtente = new JLabel("ID utente");
		lblNomeUtente.setBounds(58, 35, 104, 14);
		contentPane.add(lblNomeUtente);
		
		textFieldNomeUtente = new JTextField();
		textFieldNomeUtente.setBounds(155, 32, 118, 20);
		contentPane.add(textFieldNomeUtente);
		textFieldNomeUtente.setColumns(10);
		
		JLabel lblPassword = new JLabel("Password");
		lblPassword.setBounds(58, 82, 64, 14);
		contentPane.add(lblPassword);
		
		passwordFieldPassUtente = new JPasswordField();
		passwordFieldPassUtente.setEchoChar('*');
		passwordFieldPassUtente.setBounds(155, 79, 118, 20);
		contentPane.add(passwordFieldPassUtente);
		
		JLabel lblRisultatoLogin = new JLabel("qui appare il messaggio nel caso di login fallito");
		lblRisultatoLogin.setBounds(114, 209, 242, 14);
		lblRisultatoLogin.setVisible(false);
		contentPane.add(lblRisultatoLogin);
				
		
		JButton btnAccedi = new JButton("Accedi");
		btnAccedi.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				//procedure per l'accesso dell'utente nella biblioteca
				String nomeUtente = textFieldNomeUtente.getText();
				@SuppressWarnings("deprecation")
				String passUtente = passwordFieldPassUtente.getText();
				if(Control.UtenteController.Login(nomeUtente, passUtente)) {
					
					EventQueue.invokeLater(new Runnable() {
						public void run() {
							try {
								FormPrestitoLibro frame = new FormPrestitoLibro();
								frame.setVisible(true);
							} catch (Exception e) {
								e.printStackTrace();
							}
						}
					});
					
				}
				else {
					lblRisultatoLogin.setText("Utente non registrato");
					lblRisultatoLogin.setVisible(true);
				}
			}
		});
		btnAccedi.setBounds(169, 146, 104, 39);
		contentPane.add(btnAccedi);
		
	}
}
