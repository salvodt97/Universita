package Boundary1;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JTextField;
import javax.swing.JLabel;

public class MainForm extends JFrame {

	private JPanel contentPane;
	private JTextField textFieldInserimentoTitolo;
	private JLabel lblTitolo;
	private JLabel lblPosizione;
	private JLabel lblNumScaffale;
	private JTextField textNumScaffale;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainForm frame = new MainForm();
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
	public MainForm() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JButton buttonCercaLibro = new JButton("Cerca Libro");
		buttonCercaLibro.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String Titolo=textFieldInserimentoTitolo.getText();
				int NumScaffale;
				NumScaffale = Integer.parseInt(textNumScaffale.getText());
				int Posizione = Control1.LibriController.cercaLibroInScaffale(Titolo, NumScaffale);
				lblPosizione.setVisible(true);;
				if(Posizione==0){
					lblPosizione.setText("Libro non trovato");
				} else {
					lblPosizione.setText("Libro trovato in posizione "+ Posizione);
				}	
			}
		});
		buttonCercaLibro.setBounds(286, 88, 117, 29);
		contentPane.add(buttonCercaLibro);
		
		textFieldInserimentoTitolo = new JTextField();
		textFieldInserimentoTitolo.setBounds(118, 35, 134, 28);
		contentPane.add(textFieldInserimentoTitolo);
		textFieldInserimentoTitolo.setColumns(10);
		
		lblTitolo = new JLabel("Titolo Libro");
		lblTitolo.setBounds(20, 41, 82, 16);
		contentPane.add(lblTitolo);
		
		
		lblPosizione = new JLabel("Scaffale");
		lblPosizione.setBounds(20, 155, 383, 16);
		lblPosizione.setVisible(false);
		contentPane.add(lblPosizione);
		
		lblNumScaffale = new JLabel("NumScaffale");
		lblNumScaffale.setBounds(20, 93, 82, 16);
		contentPane.add(lblNumScaffale);
		
		textNumScaffale = new JTextField();
		textNumScaffale.setBounds(121, 87, 134, 28);
		contentPane.add(textNumScaffale);
		textNumScaffale.setColumns(10);
		
	}
}
