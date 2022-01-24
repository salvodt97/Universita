package Client;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;



import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;

public class UIFunzioniMedico extends JFrame  {

	private JPanel contentPane;
	
	private JButton btnAggiornaCartellaClinica;
	private JButton btnVisualizzaCartella;
	private JButton btnAggiornaCartella;
	private JButton btnPrenotaEsame;
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
					try {
						ArrayList<String> info=new ArrayList<String>();
					UIFunzioniMedico frame = new UIFunzioniMedico(info);
					frame.setVisible(true);	
					}catch(Exception e) {
						e.printStackTrace();
					}
					
					
				
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public UIFunzioniMedico(ArrayList<String> info) {
		setResizable(false);
		setTitle("Dott. "+ info.get(0)+" "+info.get(1));
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 548, 422);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		btnAggiornaCartellaClinica = new JButton("Crea cartella clinica");
		btnAggiornaCartellaClinica.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				
				
				dispose();
				UICreazione finestra=new UICreazione(info);
				finestra.setVisible(true);
				
			}
		});
		btnAggiornaCartellaClinica.setBounds(119, 43, 289, 25);
		contentPane.add(btnAggiornaCartellaClinica);
		
		btnVisualizzaCartella = new JButton("Visualizza cartella clinica");
		btnVisualizzaCartella.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				
				dispose();
				UIVisualizzazione finestra=new UIVisualizzazione(info);
				finestra.setVisible(true);
				
				
				
			}
		});
		btnVisualizzaCartella.setBounds(119, 92, 289, 25);
		contentPane.add(btnVisualizzaCartella);
		
		btnAggiornaCartella = new JButton("Aggiorna cartella clinica");
		btnAggiornaCartella.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				
				dispose();
				UIAggiornamento finestra=new UIAggiornamento(info);
				finestra.setVisible(true);
				
				
			}
		});
		btnAggiornaCartella.setBounds(119, 136, 289, 25);
		contentPane.add(btnAggiornaCartella);
		
		btnPrenotaEsame = new JButton("Prenota esame");
		btnPrenotaEsame.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				JOptionPane.showMessageDialog(null,"Funzionalità al momento non disponibile");
			}
				
			
		});
		
		btnPrenotaEsame.setBounds(119, 182, 289, 25);
		contentPane.add(btnPrenotaEsame);
		
		JButton btnTorna_indietro = new JButton("Log out");
		btnTorna_indietro.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				
				dispose();
				LoginUI finestra=new LoginUI();
				finestra.setVisible(true);
				
			}
		});
		btnTorna_indietro.setBounds(434, 341, 90, 28);
		contentPane.add(btnTorna_indietro);
	}
}
