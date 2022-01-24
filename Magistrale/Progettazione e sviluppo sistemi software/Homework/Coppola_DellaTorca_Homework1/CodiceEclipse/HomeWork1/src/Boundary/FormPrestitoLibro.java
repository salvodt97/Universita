package Boundary;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JDesktopPane;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.concurrent.TimeUnit;

public class FormPrestitoLibro extends JFrame {

	private JPanel contentPane;
	private JTextField textFieldTitoloLibroPrestito;


	public FormPrestitoLibro() {
		setTitle("Richiesta prestito di un libro");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblTitoloLibroPrestito = new JLabel("Inserisci il titolo del libro");
		lblTitoloLibroPrestito.setBounds(61, 34, 153, 14);
		contentPane.add(lblTitoloLibroPrestito);
		
		JLabel lblRisultato = new JLabel("Risultato della ricerca, o della conferma del prestito");
		lblRisultato.setBounds(61, 199, 291, 14);
		lblRisultato.setVisible(false);
		contentPane.add(lblRisultato);
		
		JLabel lblEsisteUnaCopia = new JLabel("Esiste una copia disponibile, \r\nconfermare il prestito?");
		lblEsisteUnaCopia.setBounds(61, 120, 301, 20);
		lblEsisteUnaCopia.setVisible(false);
		contentPane.add(lblEsisteUnaCopia);
		
		JButton btnConfermaPrestito = new JButton("Si");
		JButton btnRifiutaPrestito = new JButton("No");
		
		textFieldTitoloLibroPrestito = new JTextField();
		textFieldTitoloLibroPrestito.setBounds(223, 31, 177, 20);
		contentPane.add(textFieldTitoloLibroPrestito);
		textFieldTitoloLibroPrestito.setColumns(10);
		
		JButton btnVerificaDisponibilita = new JButton("Verifica disponibilit\u00E0");
		btnVerificaDisponibilita.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				if(Control.UtenteController.ricercaCopieDisponibili(textFieldTitoloLibroPrestito.getText())){
					lblEsisteUnaCopia.setVisible(true);
					btnConfermaPrestito.setVisible(true);
					btnRifiutaPrestito.setVisible(true);
				}
				else {
					lblRisultato.setText("Non è disponibile nessuna copia");
					lblRisultato.setVisible(true);
				}
			}
		});
		btnVerificaDisponibilita.setBounds(136, 72, 153, 37);
		contentPane.add(btnVerificaDisponibilita);
		
		
		btnConfermaPrestito.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				lblRisultato.setText("Prestito confermato");
				lblRisultato.setVisible(true);
				lblEsisteUnaCopia.setVisible(false);
				btnConfermaPrestito.setVisible(false);
				btnRifiutaPrestito.setVisible(false);
			}
		});
		btnConfermaPrestito.setBounds(108, 151, 89, 23);
		btnConfermaPrestito.setVisible(false);
		contentPane.add(btnConfermaPrestito);
		
		
		btnRifiutaPrestito.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				lblRisultato.setText("Prestito non confermato");
				lblRisultato.setVisible(true);
				lblEsisteUnaCopia.setVisible(false);
				btnConfermaPrestito.setVisible(false);
				btnRifiutaPrestito.setVisible(false);

				
			}
		});
		btnRifiutaPrestito.setBounds(223, 151, 89, 23);
		btnRifiutaPrestito.setVisible(false);
		contentPane.add(btnRifiutaPrestito);
		
	}
}
