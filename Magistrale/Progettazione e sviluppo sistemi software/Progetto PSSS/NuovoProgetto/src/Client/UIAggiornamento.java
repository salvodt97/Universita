package Client;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JInternalFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.event.ListSelectionListener;

import Server.metodi;

import java.awt.event.ActionListener;
import java.awt.TextArea;
import java.awt.event.ActionEvent;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JList;
import javax.swing.event.ListSelectionEvent;
import javax.swing.DefaultComboBoxModel;

public class UIAggiornamento {

	private JFrame frmAggiornaCartellaClinica;
	private JTextField textfield_nome;
	private JTextField textField_cognome;
	private JTextField textField_data_di_nascita;
	private JTextField textField_luogo_di_nascita;
	private JTextField textField_recapito;
	private JTextField textField_codice_fiscale;
	private JTextField textField_principio_attivo;
	private JTextField textField_posologia;
	private JTextField textField_dosaggio;
	private JTextField textField_motivo_ricovero;
	private JTextField textField_codice_ricerca;
	private JTextField textField_indirizzo;
	private JTextField textField_numero_documento;
	private TextArea textArea_anamnesi;
	private TextArea textArea_terapie;
	private JCheckBox chckbxCartella_attiva;
	private JComboBox comboBox_tipo_documento;
	private JLabel lblData_ricovero;
	private JLabel lblData_ricovero_paziente;
	
	
	public UIAggiornamento(ArrayList<String> info) {
		frmAggiornaCartellaClinica=new JFrame();
		frmAggiornaCartellaClinica.setResizable(false);
		frmAggiornaCartellaClinica.setTitle("Aggiorna cartella clinica");
		frmAggiornaCartellaClinica.setVisible(true);
		frmAggiornaCartellaClinica.setBounds(100, 100, 791, 755);
		frmAggiornaCartellaClinica.getContentPane().setLayout(null);
		
		JButton btnTornaIndietro = new JButton("Torna indietro");
		btnTornaIndietro.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			}
		});
		btnTornaIndietro.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				frmAggiornaCartellaClinica.dispose();
				UIFunzioniMedico finestra = new UIFunzioniMedico(info);
				finestra.setVisible(true);
			
			}
		});
		btnTornaIndietro.setBounds(514, 653, 114, 25);
		frmAggiornaCartellaClinica.getContentPane().add(btnTornaIndietro);
		
		JButton btnAggiornaCartella = new JButton("Aggiorna cartella");
		btnAggiornaCartella.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
				  	if(isNumeric(textField_recapito.getText())) {
				  		if(isAlpha(textfield_nome.getText())) {
				  			if(isAlpha(textField_cognome.getText())) {
				  				if(textArea_anamnesi.getText().length()<=255) {
			
					 Registry registry = LocateRegistry.getRegistry(1099);
			            metodi stub = (metodi) registry.lookup("facade");
			          stub.aggiornaCartellaClinica(textfield_nome.getText(),textField_cognome.getText(),textField_data_di_nascita.getText(),textField_luogo_di_nascita.getText(),
			            						textField_recapito.getText(),textField_codice_fiscale.getText(),textField_principio_attivo.getText(),textField_posologia.getText(),
			            						textField_dosaggio.getText(),textField_motivo_ricovero.getText(),textField_codice_ricerca.getText(),textField_indirizzo.getText(),textField_numero_documento.getText(),(String) comboBox_tipo_documento.getSelectedItem(),textArea_anamnesi.getText(),chckbxCartella_attiva.isSelected(),info);
			          
			            JOptionPane.showMessageDialog(null,"Cartella clinica aggiornata!");
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
			
		});
		btnAggiornaCartella.setBounds(633, 653, 134, 25);
		frmAggiornaCartellaClinica.getContentPane().add(btnAggiornaCartella);
		
		JInternalFrame frmInserisciPazienteFrame_1 = new JInternalFrame("Dati anagrafici");
		frmInserisciPazienteFrame_1.setBounds(12, 46, 755, 143);
		frmAggiornaCartellaClinica.getContentPane().add(frmInserisciPazienteFrame_1);
		frmInserisciPazienteFrame_1.getContentPane().setLayout(null);
		
		JLabel lblNome_paziente = new JLabel("Nome");
		lblNome_paziente.setBounds(12, 13, 56, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(lblNome_paziente);
		
		textfield_nome = new JTextField();
		textfield_nome.setBounds(60, 10, 116, 22);
		frmInserisciPazienteFrame_1.getContentPane().add(textfield_nome);
		textfield_nome.setColumns(10);
		
		JLabel Cognome_paziente = new JLabel("Cognome");
		Cognome_paziente.setBounds(188, 13, 56, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(Cognome_paziente);
		
		textField_cognome = new JTextField();
		textField_cognome.setBounds(256, 10, 116, 22);
		frmInserisciPazienteFrame_1.getContentPane().add(textField_cognome);
		textField_cognome.setColumns(10);
		
		JLabel lblData_di_nascita = new JLabel("Data di nascita");
		lblData_di_nascita.setBounds(12, 45, 91, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(lblData_di_nascita);
		
		textField_data_di_nascita = new JTextField();
		textField_data_di_nascita.setBounds(115, 45, 116, 23);
		frmInserisciPazienteFrame_1.getContentPane().add(textField_data_di_nascita);
		textField_data_di_nascita.setColumns(10);
		
		JLabel lblLuogo_di_nascita = new JLabel("Luogo di nascita");
		lblLuogo_di_nascita.setBounds(266, 45, 106, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(lblLuogo_di_nascita);
		
		textField_luogo_di_nascita = new JTextField();
		textField_luogo_di_nascita.setBounds(372, 41, 128, 23);
		frmInserisciPazienteFrame_1.getContentPane().add(textField_luogo_di_nascita);
		textField_luogo_di_nascita.setColumns(10);
		
		JLabel lblRecapito_telefonico = new JLabel("Recapito");
		lblRecapito_telefonico.setBounds(423, 13, 56, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(lblRecapito_telefonico);
		
		textField_recapito = new JTextField();
		textField_recapito.setBounds(491, 10, 116, 22);
		frmInserisciPazienteFrame_1.getContentPane().add(textField_recapito);
		textField_recapito.setColumns(10);
		
		JLabel lblCodice_fiscale = new JLabel("Codice fiscale");
		lblCodice_fiscale.setBounds(12, 78, 106, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(lblCodice_fiscale);
		
		textField_codice_fiscale = new JTextField();
		textField_codice_fiscale.setEditable(false);
		textField_codice_fiscale.setBounds(115, 75, 116, 24);
		frmInserisciPazienteFrame_1.getContentPane().add(textField_codice_fiscale);
		textField_codice_fiscale.setColumns(10);
		
		JLabel lblIndirizzo = new JLabel("Indirizzo");
		lblIndirizzo.setBounds(256, 78, 56, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(lblIndirizzo);
		
		textField_indirizzo = new JTextField();
		textField_indirizzo.setBounds(324, 75, 133, 24);
		frmInserisciPazienteFrame_1.getContentPane().add(textField_indirizzo);
		textField_indirizzo.setColumns(10);
		
		JLabel lblNewLabel = new JLabel("Numero documento");
		lblNewLabel.setBounds(512, 45, 116, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(lblNewLabel);
		
		JLabel lblNewLabel_2 = new JLabel("Tipo documento");
		lblNewLabel_2.setBounds(479, 78, 106, 16);
		frmInserisciPazienteFrame_1.getContentPane().add(lblNewLabel_2);
		
		textField_numero_documento = new JTextField();
		textField_numero_documento.setBounds(636, 39, 101, 22);
		frmInserisciPazienteFrame_1.getContentPane().add(textField_numero_documento);
		textField_numero_documento.setColumns(10);
		
		comboBox_tipo_documento = new JComboBox();
		comboBox_tipo_documento.setModel(new DefaultComboBoxModel(new String[] {"Carta di identita'", "Patente", "Passaporto"}));
		//comboBox_tipo_documento.set
		comboBox_tipo_documento.setBounds(601, 73, 136, 26);
		frmInserisciPazienteFrame_1.getContentPane().add(comboBox_tipo_documento);
		
		
		JInternalFrame frmInserisciPazienteFrame = new JInternalFrame("Aggiungi terapia");
		frmInserisciPazienteFrame.setBounds(12, 557, 755, 84);
		frmAggiornaCartellaClinica.getContentPane().add(frmInserisciPazienteFrame);
		frmInserisciPazienteFrame.getContentPane().setLayout(null);
		
		JLabel lblPrincipioAttivo = new JLabel("Principio attivo");
		lblPrincipioAttivo.setBounds(12, 13, 95, 16);
		frmInserisciPazienteFrame.getContentPane().add(lblPrincipioAttivo);
		
		textField_principio_attivo = new JTextField();
		textField_principio_attivo.setBounds(107, 10, 158, 22);
		frmInserisciPazienteFrame.getContentPane().add(textField_principio_attivo);
		textField_principio_attivo.setColumns(10);
		
		JLabel lblPosologia = new JLabel("Posologia");
		lblPosologia.setBounds(277, 13, 56, 16);
		frmInserisciPazienteFrame.getContentPane().add(lblPosologia);
		
		JLabel lblDosaggio = new JLabel("Dosaggio");
		lblDosaggio.setBounds(494, 13, 65, 16);
		frmInserisciPazienteFrame.getContentPane().add(lblDosaggio);
		
		textField_posologia = new JTextField();
		textField_posologia.setBounds(351, 10, 116, 22);
		frmInserisciPazienteFrame.getContentPane().add(textField_posologia);
		textField_posologia.setColumns(10);
		
		textField_dosaggio = new JTextField();
		textField_dosaggio.setBounds(571, 10, 138, 22);
		frmInserisciPazienteFrame.getContentPane().add(textField_dosaggio);
		textField_dosaggio.setColumns(10);
		
		JInternalFrame frmInserisciPazienteFrame_2 = new JInternalFrame("Informazioni ricovero");
		frmInserisciPazienteFrame_2.setBounds(12, 201, 755, 190);
		frmAggiornaCartellaClinica.getContentPane().add(frmInserisciPazienteFrame_2);
		frmInserisciPazienteFrame_2.getContentPane().setLayout(null);
		
		JLabel lblMotivoRicovero = new JLabel("Motivo del ricovero");
		lblMotivoRicovero.setBounds(12, 13, 116, 16);
		frmInserisciPazienteFrame_2.getContentPane().add(lblMotivoRicovero);
		
		textField_motivo_ricovero = new JTextField();
		textField_motivo_ricovero.setBounds(140, 10, 205, 25);
		frmInserisciPazienteFrame_2.getContentPane().add(textField_motivo_ricovero);
		textField_motivo_ricovero.setColumns(10);
		
		JLabel lblNewLabel_1 = new JLabel("Anamnesi patologica prossima");
		lblNewLabel_1.setBounds(12, 56, 181, 16);
		frmInserisciPazienteFrame_2.getContentPane().add(lblNewLabel_1);
		
		textArea_anamnesi = new TextArea();
		textArea_anamnesi.setBounds(205, 53, 522, 95);
		frmInserisciPazienteFrame_2.getContentPane().add(textArea_anamnesi);
		
		chckbxCartella_attiva = new JCheckBox("Cartella attiva");
		chckbxCartella_attiva.setSelected(true);
		chckbxCartella_attiva.setBounds(12, 109, 113, 25);
		frmInserisciPazienteFrame_2.getContentPane().add(chckbxCartella_attiva);
		
		lblData_ricovero = new JLabel("Data ricovero");
		lblData_ricovero.setBounds(411, 13, 103, 16);
		frmInserisciPazienteFrame_2.getContentPane().add(lblData_ricovero);
		
		lblData_ricovero_paziente = new JLabel("");
		lblData_ricovero_paziente.setBounds(526, 13, 153, 16);
		frmInserisciPazienteFrame_2.getContentPane().add(lblData_ricovero_paziente);
		
		JLabel lblCod_fiscale = new JLabel("Codice fiscale paziente ");
		lblCod_fiscale.setBounds(12, 13, 152, 16);
		frmAggiornaCartellaClinica.getContentPane().add(lblCod_fiscale);
		
		textField_codice_ricerca = new JTextField();
		textField_codice_ricerca.setBounds(176, 10, 194, 24);
		frmAggiornaCartellaClinica.getContentPane().add(textField_codice_ricerca);
		textField_codice_ricerca.setColumns(10);
		
		JButton btnCercaPaziente = new JButton("Cerca paziente");
		btnCercaPaziente.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				try {
					 Registry registry = LocateRegistry.getRegistry(1099);
			            metodi stub = (metodi) registry.lookup("facade");
			            String[][] ritorno = stub.cercaCartellaClinica(textField_codice_ricerca.getText() ,info);
			            
			            if(ritorno[0][2].equals("")) {
			            	
				             JOptionPane.showMessageDialog(null,"Il paziente non esiste");
				            }else {
				            	textfield_nome.setText(ritorno[0][0]);
				            	textField_cognome.setText(ritorno[0][1]);
				            	textField_codice_fiscale.setText(ritorno[0][2]);
				            	textField_data_di_nascita.setText(ritorno[0][3]);
				            	textField_indirizzo.setText(ritorno[0][4]);
				            	textField_luogo_di_nascita.setText(ritorno[0][5]);
				            	textField_numero_documento.setText(ritorno[0][6]);
				            	comboBox_tipo_documento.setToolTipText(ritorno[0][7]);
				            	textField_recapito.setText(ritorno[0][8]);
				            	textArea_anamnesi.setText(ritorno[0][9]);
				            	lblData_ricovero_paziente.setText(ritorno[0][10]);
				            	textField_motivo_ricovero.setText(ritorno[0][12]);
				            	String s=new String();
				            	String appoggio=new String();
				            	for(int i=1;i<ritorno.length;i++) {
				            	s="Terapia "+i+"\n:Principio attivo: "+ ritorno[i][0]+ " Posologia: "+ ritorno[i][1]+ " Dosaggio: "+ ritorno[i][2]+ " Data inizio: "+ ritorno[i][3]+ "; \n";
				            	appoggio=s+appoggio;
				            	System.out.println(s);
				            	}
				            	comboBox_tipo_documento.setToolTipText(ritorno[0][7]);
				            	textArea_terapie.setText(appoggio);
				            	lblData_ricovero_paziente.setVisible(true);				            	
				            	
				            	
				            }
				         
				            
				        } catch (Exception ex) {
				            System.err.println("Client exception: " + ex.toString());
				            JOptionPane.showMessageDialog(null,"Codice fiscale errato");
				            ex.printStackTrace();
				        }
			            
			     
			            
			}
				
				
				
			
		});
		btnCercaPaziente.setBounds(413, 9, 126, 25);
		frmAggiornaCartellaClinica.getContentPane().add(btnCercaPaziente);
		
		
		
		
		
		JInternalFrame internalFrame = new JInternalFrame("Terapie");
		internalFrame.setBounds(12, 403, 755, 142);
		frmAggiornaCartellaClinica.getContentPane().add(internalFrame);
		internalFrame.getContentPane().setLayout(null);
		
		textArea_terapie = new TextArea();
		textArea_terapie.setEditable(false);
		textArea_terapie.setBounds(210, 6, 527, 99);
		internalFrame.getContentPane().add(textArea_terapie);
		
		JLabel lblTerapie_in_corso = new JLabel("Terapie in corso");
		lblTerapie_in_corso.setBounds(41, 12, 112, 16);
		internalFrame.getContentPane().add(lblTerapie_in_corso);
		internalFrame.setVisible(true);
		frmInserisciPazienteFrame_2.setVisible(true);
		frmInserisciPazienteFrame.setVisible(true);
		frmInserisciPazienteFrame_1.setVisible(true);
		
	}



	public void setVisible(boolean b) {
		frmAggiornaCartellaClinica.setVisible(b);
		
	}
}

