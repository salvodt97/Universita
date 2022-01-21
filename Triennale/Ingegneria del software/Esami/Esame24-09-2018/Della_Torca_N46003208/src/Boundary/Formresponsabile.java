package Boundary;
import Control.Controllerresponsabile;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class Formresponsabile extends JFrame {

	private JPanel contentPane;
	private JTextField textField;
	private JLabel lblesito;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Formresponsabile frame = new Formresponsabile();
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
	public Formresponsabile() {
		
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 650, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblInserireDataDi = new JLabel("Inserire targa interesse");
		lblInserireDataDi.setBounds(10, 26, 172, 28);
		contentPane.add(lblInserireDataDi);
		
		textField = new JTextField();
		textField.setBounds(10, 50, 182, 28);
		contentPane.add(textField);
		textField.setColumns(10);
		
		JButton buttonContaEsami = new JButton("Carica dati");
		buttonContaEsami.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String targa=textField.getText();
				String esito = Control.Controllerresponsabile.visualizza_richieste(targa);
				lblesito.setVisible(true);;
				lblesito.setText(esito);	
			}
		});
		buttonContaEsami.setBounds(436, 42, 132, 50);
		contentPane.add(buttonContaEsami);
		
		lblesito = new JLabel();
		lblesito.setBounds(10, 185, 624, 50);
		lblesito.setVisible(false);
		contentPane.add(lblesito);
	}
}

