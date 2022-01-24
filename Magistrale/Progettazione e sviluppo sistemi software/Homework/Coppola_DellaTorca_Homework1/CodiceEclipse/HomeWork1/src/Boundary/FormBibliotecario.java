package Boundary;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.Panel;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JLayeredPane;
import javax.swing.JTabbedPane;

public class FormBibliotecario extends JFrame {

	private JPanel contentPane;
	private final JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
	private JTextField textFieldTitoloRicercaLibro;
	private JTextField textFieldNumeroScaffale;
	private JTextField textFieldTitoloLibroPrestiti;

	/**
	 * Create the frame.
	 */
	public FormBibliotecario() {
		setTitle("Interfaccia Bibliotecario");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		tabbedPane.setToolTipText("");
		tabbedPane.setBounds(0, 0, 434, 261);
		contentPane.add(tabbedPane);
		
		JPanel panelCercaLibro = new JPanel();
		tabbedPane.addTab("Ricerca Libro", null, panelCercaLibro, null);
		panelCercaLibro.setLayout(null);
		
		JLabel lblTitoloCercaLibro = new JLabel("Titolo del libro da cercare");
		lblTitoloCercaLibro.setBounds(45, 31, 166, 14);
		panelCercaLibro.add(lblTitoloCercaLibro);
		
		textFieldTitoloRicercaLibro = new JTextField();
		textFieldTitoloRicercaLibro.setBounds(221, 28, 166, 20);
		panelCercaLibro.add(textFieldTitoloRicercaLibro);
		textFieldTitoloRicercaLibro.setColumns(10);
		
		JLabel lblNumeroScaffale = new JLabel("Numero scaffale dove cercare");
		lblNumeroScaffale.setBounds(45, 79, 179, 14);
		panelCercaLibro.add(lblNumeroScaffale);
		
		JLabel lblRisultatoRicerca = new JLabel("qui comparir\u00E0 il risutato della ricerca");
		lblRisultatoRicerca.setBounds(95, 165, 264, 14);
		lblRisultatoRicerca.setVisible(false);
		panelCercaLibro.add(lblRisultatoRicerca);
		
		textFieldNumeroScaffale = new JTextField();
		textFieldNumeroScaffale.setBounds(263, 76, 96, 20);
		panelCercaLibro.add(textFieldNumeroScaffale);
		textFieldNumeroScaffale.setColumns(10);
		
		JButton btnCercaLibro = new JButton("Cerca Libro");
		btnCercaLibro.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				//procedure per il click sulla ricerca del libro
				String Titolo=textFieldTitoloRicercaLibro.getText();
				int NumScaffale;
				NumScaffale = Integer.parseInt(textFieldNumeroScaffale.getText());
				int Posizione = Control.BibliotecarioController.cercaLibroInScaffale(Titolo, NumScaffale);
				lblRisultatoRicerca.setVisible(true);
				if(Posizione==0){
					lblRisultatoRicerca.setText("Libro o scaffale non trovato");
				} else {
					lblRisultatoRicerca.setText("Libro trovato in posizione "+ Posizione);
				}
			}
		});
		btnCercaLibro.setBounds(144, 117, 132, 23);
		panelCercaLibro.add(btnCercaLibro);
		

		JPanel panelVisualizzaPrestiti = new JPanel();
		tabbedPane.addTab("Visualizza Prestiti", null, panelVisualizzaPrestiti, null);
		panelVisualizzaPrestiti.setLayout(null);
		
		
		JLabel lblNomeLibroPrestiti = new JLabel("Titolo libro");
		lblNomeLibroPrestiti.setBounds(78, 34, 89, 14);
		panelVisualizzaPrestiti.add(lblNomeLibroPrestiti);
		
		textFieldTitoloLibroPrestiti = new JTextField();
		textFieldTitoloLibroPrestiti.setBounds(186, 31, 182, 20);
		panelVisualizzaPrestiti.add(textFieldTitoloLibroPrestiti);
		textFieldTitoloLibroPrestiti.setColumns(10);
		
		JLabel lblRisultatoPrestiti = new JLabel("qui compare il numero di copie in prestito");
		lblRisultatoPrestiti.setBounds(34, 131, 351, 14);
		lblRisultatoPrestiti.setVisible(false);
		panelVisualizzaPrestiti.add(lblRisultatoPrestiti);
		
		JButton btnVisualizzaPrestiti = new JButton("Visualizza prestiti");
		btnVisualizzaPrestiti.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				//procedure per il click sul button per visualizzare i prestiti

				if(Control.BibliotecarioController.visualizzaNumPrestiti(textFieldTitoloLibroPrestiti.getText()) > 0) {
					lblRisultatoPrestiti.setText("il numero di prestiti effettuati è pari a " + 
							Control.BibliotecarioController.visualizzaNumPrestiti(textFieldTitoloLibroPrestiti.getText()));
					lblRisultatoPrestiti.setVisible(true);
				}
				else {
					lblRisultatoPrestiti.setText("Non esistono prestiti effettuati per il libro scelto");
					lblRisultatoPrestiti.setVisible(true);
				}
				
			}
		});
		btnVisualizzaPrestiti.setBounds(139, 76, 142, 23);
		panelVisualizzaPrestiti.add(btnVisualizzaPrestiti);
		
		
		
		
	}
}
