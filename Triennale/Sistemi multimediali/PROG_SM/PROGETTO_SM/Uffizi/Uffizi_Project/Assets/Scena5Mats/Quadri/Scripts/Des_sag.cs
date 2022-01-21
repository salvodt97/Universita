using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_sag : MonoBehaviour
{
    public Text testo;
    private bool pressione = false;
    private int contatore;
    // Start is called before the first frame update
    void Start()
    {
        pressione = true;
        contatore = 0;
        testo = GetComponent<Text>();
        if (testo)
        {
            testo.text = " ";
        }
    }

    public void ApriDescrizione()
    {

        if (pressione)
        {
            contatore = contatore + 1;
            if (contatore % 2 != 1)
            {
                if (testo)
                {
                    testo.text = "";
                }
            }
            else
            {
                if (testo)
                {
                    if (variabile.italiano)
                    {
                        testo.text = "La qualità altissima di quest’opera è messa in risalto dalla splendida cornice intagliata con figure di \nangeli - puttini che recano in mano gli strumenti della Passione(corona di spine, tenaglie, la colonna, la \nfrusta, la lancia), riferimenti iconografici al destino di sofferenza del bambino Gesù, raffigurato al centro \ndella tela con la madre, San Giuseppe e il piccolo San Giovannino, mentre viene avvicinato da una regale \nSanta Caterina.Il marcato plasticismo degli intagli e il disegno complessivo della cornice fanno propendere \nper una sua assegnazione alla manifattura romana della metà del XVII secolo, su disegno di Pietro da Cortona, \nil grande artista barocco che a Firenze fu chiamato dai granduchi medicei a lavorare per la decorazione a fresco\ndi Palazzo Pitti. Dipinta da Paolo Veronese intorno al 1565 e conservata a Venezia nella collezione Widmann, la \ntela fu acquistata dai Serenissimi principi di Toscana Leopoldo e Giovan Carlo de’ Medici nel 1654 a seguito della \nproposta del mercante fiorentino, ma residente a Venezia, Paolo del Sera. Per l’acquisto fu pagata la somma altissima \ndi 1000 scudi a riprova della preponderante fortuna del Veronese fra i collezionisti e gli intendenti d’arte nel solco \ndel gusto neo-veneto della cultura figurativa di età barocca.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "The high quality of this work is highlighted by the beautiful frame carved with figures of angels -whores \nholding in their hands the instruments of the Passion(crown of thorns, pincers, the column, the whip, the \nspear), iconographic references to the fate of suffering of the child Jesus, depicted in the center of the canvas \nwith his mother, St. Joseph and the young St.John, while he is approached by a royal St. Catherine.The \nmarked plasticism of the carvings and the overall design of the frame suggest that it should be assigned \nto the Roman manufacture of the mid-seventeenth century, designed by Pietro da Cortona, the great baroque artist \nwho in Florence was called by the Medici grand dukes to work on the fresco decoration of Palazzo Pitti.Painted \nby Paolo Veronese around 1565 and kept in Venice in the Widmann collection, the canvas was purchased by the \nSerenissimi principi di Toscana Leopoldo and Giovan Carlo de' Medici in 1654 following the proposal of the Florentine \nmerchant, but resident in Venice, Paolo del Sera. For the purchase was paid the very high sum of 1000 shields as proof \nof the preponderant fortune of the Veronese among collectors and connoisseurs of art in the wake of the neo-venetian taste \nof figurative culture of the Baroque period";
                    }
                }
            }
        }
    }
}
