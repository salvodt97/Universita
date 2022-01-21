using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_fra : MonoBehaviour
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
                    if(variabile.italiano)
                    {
                        testo.text = "L’esecuzione del ritratto di Francesco Maria duca di Urbino, (1490-1538) di Tiziano è documentata\nnegli anni fra il 1536 e il 1538.Nell’estate del 1536 il duca chiede che gli venga restituita l’armatura \nda parata spedita pochi mesi prima a Venezia affinché Tiziano la riproducesse accuratamente \nnel ritratto che l’artista andava dipingendo, avvalendosi della presenza nella città lagunare del \nduca d’Urbino in qualità di Capitano Generale della Serenissima.Tiziano ritrae Francesco Maria \na mezza coscia con il bastone del comando veneziano stretto in pugno e l’armatura luccicante \nche risalta sullo sfondo di un drappo di velluto cremisi.Sotto l’armatura, com’è visibile nelle \nmaniche, il duca indossa un abito realizzato con i colori nero e giallo, i colori araldici della casata \ndei Montefeltro in ricordo della sua appartenenza a questa stirpe, quale figlio di Giovanna da Montefeltro \ne nipote del celebre condottiero Federico.Sulla mensola alle sue spalle a sinistra compare un elmo \nsovrastato da un drago, mentre a destra sono raffigurati i bastoni del comando delle truppe del papato, \ndi Firenze e di Venezia con un ramo di rovere, in riferimento alla discendenza di Francesco \nMaria anche dalla casata dei della Rovere di cui era stato illustre esponente lo zio, il papa Giulio II \ndella Rovere.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "The execution of the portrait of Francesco Maria Duke of Urbino, (1490-1538) by Titian is documented \nin the years between 1536 and 1538. In the summer of 1536, the Duke asked for the armor to be returned \nto him for a parade sent a few months earlier to Venice so that Titian could accurately reproduce it \nin the portrait that the artist was painting, making use of the presence in the lagoon city o\nf the Duke of Urbino as Captain General of the Serenissima.Titian portrays Francesco Maria \nin the middle of the thigh with the stick of the Venetian command in his hand and the shiny armor \nthat stands out against the background of a crimson velvet drape.Under the armour, as can \nbe seen in the sleeves, the duke wears a dress made in black and yellow, the heraldic colours of the \nMontefeltro family, in memory of his belonging to this lineage, as the son of Giovanna da Montefeltro, the \nnephew of the famous leader Federico.On the shelf behind him, on the left, there is a helmet \nsurmounted by a dragon, while on the right there are the sticks of the command of the troops of the papacy, \nof Florence and Venice with an oak branch, in reference to the descent of Francis \n Mary also from \nthe family of the Oak of which his uncle, Pope Julius II \n of the Oak, had been an illustrious \nexponent";
                    }
                }
            }
        }
    }
}
