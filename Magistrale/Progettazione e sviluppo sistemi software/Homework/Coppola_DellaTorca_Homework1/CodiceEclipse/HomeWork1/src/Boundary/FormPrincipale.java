package Boundary;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.GridBagLayout;
import javax.swing.JLabel;
import java.awt.GridBagConstraints;
import javax.swing.JButton;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class FormPrincipale extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		
		
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					FormPrincipale frame = new FormPrincipale();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public FormPrincipale() {
		setTitle("Benvenuto");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel labelChiSei = new JLabel("Seleziona un'opzione");
		labelChiSei.setBounds(163, 41, 131, 14);
		contentPane.add(labelChiSei);
		
		JButton btnSezioneUtente = new JButton("Utente");
		btnSezioneUtente.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				//avvio interfaccia utente
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							FormUtente frameUtente = new FormUtente();
							frameUtente.setVisible(true);
							
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
			}
		});
		btnSezioneUtente.setBounds(58, 113, 108, 46);
		contentPane.add(btnSezioneUtente);
		
		JButton btnSezioneBibliotecario = new JButton("Bibliotecario");
		btnSezioneBibliotecario.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				//avvio interfaccia bibliotecario
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							FormBibliotecario frame = new FormBibliotecario();
							frame.setVisible(true);
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
			}
		});
		btnSezioneBibliotecario.setBounds(270, 113, 108, 46);
		contentPane.add(btnSezioneBibliotecario);
	}

}
