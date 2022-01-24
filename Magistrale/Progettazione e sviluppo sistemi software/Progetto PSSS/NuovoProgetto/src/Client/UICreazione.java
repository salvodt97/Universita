package Client;

//import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JInternalFrame;
import javax.swing.JTextField;

import Server.metodi;


import java.awt.BorderLayout;
import javax.swing.JLabel;
//import com.jgoodies.forms.layout.FormLayout;
//import com.jgoodies.forms.layout.ColumnSpec;
//import com.jgoodies.forms.layout.RowSpec;
import javax.swing.JTextArea;
import javax.swing.JComboBox;
import javax.swing.JScrollBar;
import javax.swing.JTable;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JButton;
import java.awt.List;
import java.awt.TextArea;
import java.awt.Choice;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.ArrayList;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class UICreazione  {
	
	private JFrame frmCreaCartellaClinica;
	private JTextField textfieldNome;
	private JTextField textField_cognome;
	private JTextField textField_data_di_nascita;
	private JTextField textField_luogo_di_nascita;
	private JTextField textField_recapito;
	private JTextField textFieldCodice_fiscale;
	private JTextField textField_principio_attivo;
	private JTextField textField_posologia;
	private JTextField textField_dosaggio;
	private JTextField textFieldMotivo_ricovero;
	private JTextField textField_Indirizzo;
	private TextArea textArea_anamnesi;
	private JTextField textField_numero_documento;
	private JComboBox comboBox_tipo_documento;
	private JTable table;
	/**
	 * Launch the application.
	 */
	

	/**
	 * Create the frame.
	 */
	public UICreazione(ArrayList<String> info) {
		
		frmCreaCartellaClinica=new JFrame();
		frmCreaCartellaClinica.setResizable(false);
		frmCreaCartellaClinica.setTitle("Crea cartella clinica");
		frmCreaCartellaClinica.setVisible(true);
		frmCreaCartellaClinica.setBounds(100, 100, 797, 547);
		frmCreaCartellaClinica.getContentPane().setLayout(null);
		
		JButton btnTornaIndietro = new JButton("Torna indietro");
		
		btnTornaIndietro.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				frmCreaCartellaClinica.dispose();
				
				UIFunzioniMedico finestra = new UIFunzioniMedico(info);
				finestra.setVisible(true);
			
			}
		});
		btnTornaIndietro.setBounds(527, 466, 114, 25);
		frmCreaCartellaClinica.getContentPane().add(btnTornaIndietro);
		
		JButton btnCrea_cartella = new JButton("Crea cartella");
		btnCrea_cartella.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				  try {
					  	if(isNumeric(textField_recapito.getText()) || textField_recapito.getText().equals("") ) {
					  		if(isAlpha(textfieldNome.getText()) || textfieldNome.getText().equals("")) {
					  			if(isAlpha(textField_cognome.getText()) || textField_cognome.getText().equals("")) {
					  				if(textArea_anamnesi.getText().length()<=255 || textArea_anamnesi.getText().equals("")) {
					  					if(textFieldCodice_fiscale.getText().length() == 16 && isLetter(textFieldCodice_fiscale.getText().charAt(0)) && isLetter(textFieldCodice_fiscale.getText().charAt(1)) && isLetter(textFieldCodice_fiscale.getText().charAt(2)) && isLetter(textFieldCodice_fiscale.getText().charAt(3)) && isLetter(textFieldCodice_fiscale.getText().charAt(4))
					  							&& isLetter(textFieldCodice_fiscale.getText().charAt(5)) && isDigit(textFieldCodice_fiscale.getText().charAt(6)) && isDigit(textFieldCodice_fiscale.getText().charAt(7)) && isLetter(textFieldCodice_fiscale.getText().charAt(8)) && isDigit(textFieldCodice_fiscale.getText().charAt(9)) && isDigit(textFieldCodice_fiscale.getText().charAt(10))
					  							&& isLetter(textFieldCodice_fiscale.getText().charAt(11)) && isDigit(textFieldCodice_fiscale.getText().charAt(12)) && isDigit(textFieldCodice_fiscale.getText().charAt(13)) && isDigit(textFieldCodice_fiscale.getText().charAt(14)) && isLetter(textFieldCodice_fiscale.getText().charAt(15))) {
					  		
			            Registry registry = LocateRegistry.getRegistry(1099);
			            metodi stub = (metodi) registry.lookup("facade");
			             int codice_cartella = stub.creaCartellaClinica(textfieldNome.getText(),textField_cognome.getText(),textField_data_di_nascita.getText(),textField_luogo_di_nascita.getText(),
							textField_recapito.getText(),textFieldCodice_fiscale.getText(),textField_principio_attivo.getText(),textField_posologia.getText(),textField_dosaggio.getText(),
							textFieldMotivo_ricovero.getText(),textField_Indirizzo.getText(),textArea_anamnesi.getText(),textField_numero_documento.getText(),(String)comboBox_tipo_documento.getSelectedItem(),info);
			            
			             JOptionPane.showMessageDialog(null,"Il codice della cartella clinica e': "+ codice_cartella);
					  					}
					  					else
					  						JOptionPane.showMessageDialog(null,"Codice fiscale errato");
					  				}
					  				else
					  					JOptionPane.showMessageDialog(null,"L'anamnesi è troppo lunga");
					  			}
					  			else
					  				JOptionPane.showMessageDialog(null,"Il cognome contiene dei numeri");
					  		}
					  		else
					  			JOptionPane.showMessageDialog(null,"Il nome contiene dei numeri");
					  	}
					  	else
					  		JOptionPane.showMessageDialog(null,"Recapito telefonico errato");
			            
			        } catch (Exception ex) {
			            System.err.println("Client exception: " + ex.toString());
			            ex.printStackTrace();
			        }
			
				
			}

			private boolean isNumeric(String stringa) {
				// TODO Auto-generated method stub
				  try {  
					    Double.parseDouble(stringa);  
					    return true;
					  } catch(NumberFormatException e){  
					    return false;  
					  } 
			}

			
			public boolean isAlpha(String name) {
			    char[] chars = name.toCharArray();

			    for (char c : chars) {
			        if(!Character.isLetter(c)) {
			            return false;
			        }
			    }

			    return true;
			}
			
			private boolean isLetter(char c) {
			    return (c >= 'a' && c <= 'z') ||
			           (c >= 'A' && c <= 'Z');
			}
			
			private boolean isDigit(char c) {
			        return   (c >= '0' && c <= '9');
			}
			
		});
		btnCrea_cartella.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
			}
		});
		btnCrea_cartella.setBounds(653, 466, 114, 25);
		frmCreaCartellaClinica.getContentPane().add(btnCrea_cartella);
		
		JInternalFrame internalFrame_1 = new JInternalFrame("Dati anagrafici");
		internalFrame_1.setBounds(12, 13, 755, 143);
		internalFrame_1.setVisible(true);
		frmCreaCartellaClinica.getContentPane().add(internalFrame_1);
		internalFrame_1.getContentPane().setLayout(null);
		
		JLabel lblNome_paziente = new JLabel("Nome");
		lblNome_paziente.setBounds(12, 13, 56, 16);
		internalFrame_1.getContentPane().add(lblNome_paziente);
		
		textfieldNome = new JTextField();
		textfieldNome.setBounds(60, 10, 116, 22);
		internalFrame_1.getContentPane().add(textfieldNome);
		textfieldNome.setColumns(10);
		
		JLabel lblCognome_paziente = new JLabel("Cognome");
		lblCognome_paziente.setBounds(188, 13, 56, 16);
		internalFrame_1.getContentPane().add(lblCognome_paziente);
		
		textField_cognome = new JTextField();
		textField_cognome.setBounds(256, 10, 116, 22);
		internalFrame_1.getContentPane().add(textField_cognome);
		textField_cognome.setColumns(10);
		
		JLabel lblData_di_nascita = new JLabel("Data di nascita");
		lblData_di_nascita.setBounds(12, 45, 91, 16);
		internalFrame_1.getContentPane().add(lblData_di_nascita);
		
		textField_data_di_nascita = new JTextField();
		textField_data_di_nascita.setBounds(115, 45, 116, 22);
		internalFrame_1.getContentPane().add(textField_data_di_nascita);
		textField_data_di_nascita.setColumns(10);
		
		JLabel lblLuogo_di_nascita = new JLabel("Luogo di nascita");
		lblLuogo_di_nascita.setBounds(266, 45, 106, 16);
		internalFrame_1.getContentPane().add(lblLuogo_di_nascita);
		
		textField_luogo_di_nascita = new JTextField();
		textField_luogo_di_nascita.setBounds(384, 42, 116, 22);
		internalFrame_1.getContentPane().add(textField_luogo_di_nascita);
		textField_luogo_di_nascita.setColumns(10);
		
		JLabel lblRecapito_telefonico = new JLabel("Recapito");
		lblRecapito_telefonico.setBounds(401, 13, 56, 16);
		internalFrame_1.getContentPane().add(lblRecapito_telefonico);
		
		textField_recapito = new JTextField();
		textField_recapito.setBounds(469, 10, 116, 22);
		internalFrame_1.getContentPane().add(textField_recapito);
		textField_recapito.setColumns(10);
		
		JLabel lblCodice_fiscale = new JLabel("Codice fiscale");
		lblCodice_fiscale.setBounds(12, 78, 106, 16);
		internalFrame_1.getContentPane().add(lblCodice_fiscale);
		
		textFieldCodice_fiscale = new JTextField();
		textFieldCodice_fiscale.setBounds(100, 75, 164, 22);
		internalFrame_1.getContentPane().add(textFieldCodice_fiscale);
		textFieldCodice_fiscale.setColumns(10);
		
		JLabel lblIndirizzo = new JLabel("Indirizzo");
		lblIndirizzo.setBounds(276, 78, 56, 16);
		internalFrame_1.getContentPane().add(lblIndirizzo);
		
		textField_Indirizzo = new JTextField();
		textField_Indirizzo.setText("");
		textField_Indirizzo.setBounds(341, 75, 140, 22);
		internalFrame_1.getContentPane().add(textField_Indirizzo);
		textField_Indirizzo.setColumns(10);
		
		JLabel lblTipo_documento = new JLabel("Tipo documento");
		lblTipo_documento.setBounds(493, 77, 109, 16);
		internalFrame_1.getContentPane().add(lblTipo_documento);
		
		String[] scelte = {"Carta di identita'","Patente","Passaporto"};
		
		
		comboBox_tipo_documento = new JComboBox(scelte);
		
		comboBox_tipo_documento.setBounds(604, 75, 123, 22);
		internalFrame_1.getContentPane().add(comboBox_tipo_documento);
		
		JLabel lblNumero_documento = new JLabel("Numero documento");
		lblNumero_documento.setBounds(512, 45, 123, 16);
		internalFrame_1.getContentPane().add(lblNumero_documento);
		
		textField_numero_documento = new JTextField();
		textField_numero_documento.setBounds(630, 42, 97, 22);
		internalFrame_1.getContentPane().add(textField_numero_documento);
		textField_numero_documento.setColumns(10);
		
		JInternalFrame internalFrame = new JInternalFrame("Terapia");
		internalFrame.setBounds(12, 372, 755, 84);
		frmCreaCartellaClinica.getContentPane().add(internalFrame);
		internalFrame.setVisible(true);
		internalFrame.getContentPane().setLayout(null);
		
		JLabel lblPrincipioAttivo = new JLabel("Principio attivo");
		lblPrincipioAttivo.setBounds(12, 13, 95, 16);
		internalFrame.getContentPane().add(lblPrincipioAttivo);
		
		textField_principio_attivo = new JTextField();
		textField_principio_attivo.setBounds(106, 10, 158, 22);
		internalFrame.getContentPane().add(textField_principio_attivo);
		textField_principio_attivo.setColumns(10);
		
		JLabel lblPosologia = new JLabel("Posologia");
		lblPosologia.setBounds(277, 13, 56, 16);
		internalFrame.getContentPane().add(lblPosologia);
		
		JLabel lblDosaggio = new JLabel("Dosaggio");
		lblDosaggio.setBounds(494, 13, 65, 16);
		internalFrame.getContentPane().add(lblDosaggio);
		
		textField_posologia = new JTextField();
		textField_posologia.setBounds(351, 10, 116, 22);
		internalFrame.getContentPane().add(textField_posologia);
		textField_posologia.setColumns(10);
		
		textField_dosaggio = new JTextField();
		textField_dosaggio.setBounds(571, 10, 138, 22);
		internalFrame.getContentPane().add(textField_dosaggio);
		textField_dosaggio.setColumns(10);
		
		JInternalFrame internalFrame_2 = new JInternalFrame("Informazioni ricovero");
		internalFrame_2.setBounds(12, 169, 755, 190);
		frmCreaCartellaClinica.getContentPane().add(internalFrame_2);
		internalFrame_2.setVisible(true);
		internalFrame_2.getContentPane().setLayout(null);
		
		JLabel lblMotivo_ricovero = new JLabel("Motivo del ricovero");
		lblMotivo_ricovero.setBounds(12, 13, 116, 16);
		internalFrame_2.getContentPane().add(lblMotivo_ricovero);
		
		textFieldMotivo_ricovero = new JTextField();
		textFieldMotivo_ricovero.setBounds(140, 10, 205, 22);
		internalFrame_2.getContentPane().add(textFieldMotivo_ricovero);
		textFieldMotivo_ricovero.setColumns(10);
		
		JLabel lblAnamnesi = new JLabel("Anamnesi patologica prossima");
		lblAnamnesi.setBounds(12, 56, 181, 16);
		internalFrame_2.getContentPane().add(lblAnamnesi);
		
		textArea_anamnesi = new TextArea();
		textArea_anamnesi.setBounds(205, 53, 522, 95);
		internalFrame_2.getContentPane().add(textArea_anamnesi);
		
		
		

	}


	public void setVisible(boolean b) {
		frmCreaCartellaClinica.setVisible(b);
		
	}
}
