package Client;

import java.awt.BorderLayout;
import java.awt.Choice;
import java.awt.Dimension;
import java.awt.EventQueue;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JInternalFrame;
import javax.swing.JInternalFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

import Server.metodi;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.ArrayList;
import java.awt.TextArea;
import java.awt.Toolkit;

import javax.swing.JEditorPane;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JComboBox;
import javax.swing.JTextArea;

public class UIVisualizzazione  {

	private JFrame frmVisualizzaCartellaClinica;
	private JLabel nome_paziente;
	private JTextField textField_ricerca_paziente;
	private JLabel Nome_paziente;
	private	JLabel cognome_paziente;
	private JLabel recapito_paziente;
	private	JLabel data_di_nascita_paziente;
	private JLabel luogo_di_nascita_paziente;
	private	JLabel lblcod_fis_paziente;
	private	JLabel lblnumero_doc_paziente;
	private	JLabel lblIndirizzo_paziente;
	private JLabel lbltipo_documento_paziente;
	private TextArea Anamnesi_patologica_prossima;
	private JLabel lblmotivo_ric_paziente;
	private TextArea Terapie_effettuate;
	private JLabel lbldata_ricovero_paziente;
	/**
	 * Launch the application.
	 */
	

	/**
	 * Create the frame.
	 */
	public UIVisualizzazione(ArrayList<String> info) {
		frmVisualizzaCartellaClinica=new JFrame();
		frmVisualizzaCartellaClinica.setResizable(false);
		frmVisualizzaCartellaClinica.setTitle("Visualizza cartella clinica");
		frmVisualizzaCartellaClinica.setVisible(true);
		frmVisualizzaCartellaClinica.setBounds(1000, 1000, 899, 787);
		frmVisualizzaCartellaClinica.getContentPane().setLayout(null);
		
		Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
		frmVisualizzaCartellaClinica.setLocation(dim.width / 2 - frmVisualizzaCartellaClinica.getWidth() / 2, dim.height / 2 - frmVisualizzaCartellaClinica.getHeight() / 2);
		
		JButton btnNewButton = new JButton("Torna indietro");
		btnNewButton.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
					
				frmVisualizzaCartellaClinica.dispose();
				if(info.get(2).equals("medico")){
				UIFunzioniMedico finestra = new UIFunzioniMedico(info);
				finestra.setVisible(true);
				}
				else {
					LoginUI finestra = new LoginUI();
					finestra.setVisible(true);
				}
			}
		});
		btnNewButton.setBounds(756, 704, 114, 25);
		frmVisualizzaCartellaClinica.getContentPane().add(btnNewButton);
		
		
		JInternalFrame frmInserisciPazienteFrame_1 = new JInternalFrame("Dati anagrafici");
		frmInserisciPazienteFrame_1.setBounds(12, 65, 858, 143);
		frmVisualizzaCartellaClinica.getContentPane().add(frmInserisciPazienteFrame_1);
		frmInserisciPazienteFrame_1.getContentPane().setLayout(null);
		
		Nome_paziente = new JLabel("Nome");
		Nome_paziente.setBounds(12, 13, 56, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(Nome_paziente);
		
		JLabel Cognome_paziente = new JLabel("Cognome");
		Cognome_paziente.setBounds(265, 13, 56, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(Cognome_paziente);
		
		JLabel data_di_nascita = new JLabel("Data di nascita");
		data_di_nascita.setBounds(12, 45, 91, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(data_di_nascita);
		
		JLabel luogo_di_nascita = new JLabel("Luogo di nascita");
		luogo_di_nascita.setBounds(266, 45, 106, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(luogo_di_nascita);
		
		JLabel recapito_telefonico = new JLabel("Recapito");
		recapito_telefonico.setBounds(547, 13, 56, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(recapito_telefonico);
		
		JLabel codice_fiscale = new JLabel("Codice fiscale");
		codice_fiscale.setBounds(12, 78, 106, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(codice_fiscale);
		
		nome_paziente = new JLabel("nome");
		nome_paziente.setBounds(64, 13, 189, 16);
		nome_paziente.setVisible(false);
		frmInserisciPazienteFrame_1.getContentPane().add(nome_paziente);
		
		
		cognome_paziente = new JLabel("cognome");
		cognome_paziente.setBounds(333, 13, 202, 16);
		cognome_paziente.setVisible(false);
		frmInserisciPazienteFrame_1.getContentPane().add(cognome_paziente);
		
		recapito_paziente = new JLabel("recapito");
		recapito_paziente.setBounds(615, 13, 93, 16);
		recapito_paziente.setVisible(false);
		frmInserisciPazienteFrame_1.getContentPane().add(recapito_paziente);
		
		data_di_nascita_paziente = new JLabel("data di nascita");
		data_di_nascita_paziente.setBounds(127, 45, 102, 16);
		data_di_nascita_paziente.setVisible(false);
		frmInserisciPazienteFrame_1.getContentPane().add(data_di_nascita_paziente);
		
		luogo_di_nascita_paziente = new JLabel("luogo di nascita");
		luogo_di_nascita_paziente.setBounds(384, 45, 148, 16);
		luogo_di_nascita_paziente.setVisible(false);
		frmInserisciPazienteFrame_1.getContentPane().add(luogo_di_nascita_paziente);
		
		lblcod_fis_paziente = new JLabel("codice fiscale");
		lblcod_fis_paziente.setBounds(116, 78, 144, 16);
		lblcod_fis_paziente.setVisible(false);
		frmInserisciPazienteFrame_1.getContentPane().add(lblcod_fis_paziente);
		
		JLabel lblNewLabel_4 = new JLabel("Numero documento");
		lblNewLabel_4.setBounds(544, 45, 122, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(lblNewLabel_4);
		
		lblnumero_doc_paziente = new JLabel("numero doc");
		lblnumero_doc_paziente.setBounds(678, 45, 130, 16);
		lblnumero_doc_paziente.setVisible(false);
		frmInserisciPazienteFrame_1.getContentPane().add(lblnumero_doc_paziente);
		
		JLabel lblIndirizzo = new JLabel("Indirizzo");
		lblIndirizzo.setBounds(278, 78, 55, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(lblIndirizzo);
		
		lblIndirizzo_paziente = new JLabel("indirizzo");
		lblIndirizzo_paziente.setBounds(331, 78, 201, 16);
		lblIndirizzo_paziente.setVisible(false);
		frmInserisciPazienteFrame_1.getContentPane().add(lblIndirizzo_paziente);
		
		JLabel lbltipo_documento = new JLabel("Tipo documento");
		lbltipo_documento.setBounds(538, 78, 106, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(lbltipo_documento);
		
		lbltipo_documento_paziente = new JLabel("tipo doc");
		lbltipo_documento_paziente.setBounds(656, 78, 113, 16);
		lbltipo_documento_paziente.setVisible(false);
		frmInserisciPazienteFrame_1.getContentPane().add(lbltipo_documento_paziente);
		
		
		
		JInternalFrame Anamnesi = new JInternalFrame("Informazioni paziente");
		Anamnesi.setBounds(6, 449, 858, 243);
		frmVisualizzaCartellaClinica.getContentPane().add(Anamnesi);
		Anamnesi.getContentPane().setLayout(null);
		
		JLabel lblNewLabel_1 = new JLabel("Anamnesi patologica prossima");
		lblNewLabel_1.setBounds(12, 13, 174, 16);
		Anamnesi.getContentPane().add(lblNewLabel_1);
		
		Anamnesi_patologica_prossima = new TextArea();
		Anamnesi_patologica_prossima.setEditable(false);
		Anamnesi_patologica_prossima.setBounds(216, 10, 616, 125);
		Anamnesi.getContentPane().add(Anamnesi_patologica_prossima);
		
		JLabel lblNewLabel_2 = new JLabel("Motivo ricovero");
		lblNewLabel_2.setBounds(12, 151, 118, 16);
		Anamnesi.getContentPane().add(lblNewLabel_2);
		
		lblmotivo_ric_paziente = new JLabel("motivo ricovero");
		lblmotivo_ric_paziente.setVisible(false);
		lblmotivo_ric_paziente.setBounds(107, 151, 141, 16);
		Anamnesi.getContentPane().add(lblmotivo_ric_paziente);
		
		JLabel lbldata_ricovero = new JLabel("Data ricovero");
		lbldata_ricovero.setBounds(298, 151, 88, 16);
		Anamnesi.getContentPane().add(lbldata_ricovero);
		
		lbldata_ricovero_paziente = new JLabel("data");
		lbldata_ricovero_paziente.setBounds(398, 151, 118, 16);
		lbldata_ricovero_paziente.setVisible(false);
		Anamnesi.getContentPane().add(lbldata_ricovero_paziente);
		Anamnesi.setVisible(true);
		frmInserisciPazienteFrame_1.setVisible(true);

		JInternalFrame Terapia = new JInternalFrame("Terapie");
		Terapia.setBounds(14, 220, 858, 217);
		Terapia.setVisible(true);
		frmVisualizzaCartellaClinica.getContentPane().add(Terapia);
		Terapia.getContentPane().setLayout(null);
		
		JLabel lblNewLabel_6 = new JLabel("Terapie effettuate");
		lblNewLabel_6.setBounds(22, 35, 124, 16);
		Terapia.getContentPane().add(lblNewLabel_6);
		
		Terapie_effettuate = new TextArea();
		Terapie_effettuate.setEditable(false);
		Terapie_effettuate.setBounds(220, 35, 616, 125);
		Terapia.getContentPane().add(Terapie_effettuate);
		
		JLabel lblCod_fiscale = new JLabel("Codice fiscale paziente da ricercare ");
		lblCod_fiscale.setBounds(12, 25, 217, 16);
		frmVisualizzaCartellaClinica.getContentPane().add(lblCod_fiscale);
		
		textField_ricerca_paziente = new JTextField();
		textField_ricerca_paziente.setBounds(259, 25, 192, 25);
		frmVisualizzaCartellaClinica.getContentPane().add(textField_ricerca_paziente);
		textField_ricerca_paziente.setColumns(10);
		
		JButton btnCercaPaziente = new JButton("Cerca paziente");
		btnCercaPaziente.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				try {
					 Registry registry = LocateRegistry.getRegistry(1099);
			            metodi stub = (metodi) registry.lookup("facade");
			            String[][] ritorno = stub.cercaCartellaClinica(textField_ricerca_paziente.getText().toUpperCase(),info);
			          
			            if(ritorno[0][2].equals("")) {
			            	
			             JOptionPane.showMessageDialog(null,"Il paziente non esiste");
			            }else {
			            	nome_paziente.setText(ritorno[0][0]);
			            	cognome_paziente.setText(ritorno[0][1]);
			            	lblcod_fis_paziente.setText(ritorno[0][2]);
			            	data_di_nascita_paziente.setText(ritorno[0][3]);
			            	lblIndirizzo_paziente.setText(ritorno[0][4]);
			            	luogo_di_nascita_paziente.setText(ritorno[0][5]);
			            	lblnumero_doc_paziente.setText(ritorno[0][6]);
			            	lbltipo_documento_paziente.setText(ritorno[0][7]);
			            	recapito_paziente.setText(ritorno[0][8]);
			            	Anamnesi_patologica_prossima.setText(ritorno[0][9]);
			            	lbldata_ricovero_paziente.setText(ritorno[0][10]);
			            	lblmotivo_ric_paziente.setText(ritorno[0][12]);
			            	String s=new String();
			            	String appoggio=new String();
			            	for(int i=1;i<ritorno.length;i++) {
			            		s="Terapia "+i+"\n:Principio attivo: "+ ritorno[i][0]+ " Posologia: "+ ritorno[i][1]+ " Dosaggio: "+ ritorno[i][2]+ " Data inizio: "+ ritorno[i][3]+ "; \n";
			            	appoggio=s+appoggio;
			            	System.out.println(s);
			            	}
			            	Terapie_effettuate.setText(appoggio);
			            	
			            	nome_paziente.setVisible(true);
			            	cognome_paziente.setVisible(true);
			            	lblcod_fis_paziente.setVisible(true);
			            	data_di_nascita_paziente.setVisible(true);
			            	lblIndirizzo_paziente.setVisible(true);
			            	luogo_di_nascita_paziente.setVisible(true);
			            	lblnumero_doc_paziente.setVisible(true);
			            	lbltipo_documento_paziente.setVisible(true);
			            	recapito_paziente.setVisible(true);
			            	lbldata_ricovero_paziente.setVisible(true);
			            	lblmotivo_ric_paziente.setVisible(true);
			            	
			            	
			            	
			            	
			            	
			            }
			         
			            
			        } catch (Exception ex) {
			            System.err.println("Client exception: " + ex.toString());
			            JOptionPane.showMessageDialog(null,"Codice fiscale errato");
			            ex.printStackTrace();
			        }
			}
		});
		btnCercaPaziente.setBounds(498, 21, 158, 25);
		frmVisualizzaCartellaClinica.getContentPane().add(btnCercaPaziente);
		
	}


	public void setVisible(boolean b) {
		frmVisualizzaCartellaClinica.setVisible(b);
		
	}
}
