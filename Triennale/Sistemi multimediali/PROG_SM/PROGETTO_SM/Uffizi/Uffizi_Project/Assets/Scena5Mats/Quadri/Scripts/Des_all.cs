using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_all : MonoBehaviour
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
                        testo.text = "Opera fra le più enigmatiche e affascinanti del Rinascimento, mostra la Madonna in trono, a sinistra, \ne un gruppo di santi e putti sopra una grande terrazza affacciata su uno specchio d’acqua, davanti a un \npaesaggio roccioso.Fra i santi si riconoscono, dietro la balaustra, Giuseppe e, con la spada del martirio, \nPaolo, mentre i due santi seminudi a destra sono l’anacoreta Onofrio, dall’aspetto incolto e con la pelle\nbruciata dal sole, e il martire Sebastiano.Gesù, ricordato anche dalla raffigurazione della croce eretta nel \npaesaggio a destra, è forse il bambino seduto sul cuscino al centro della composizione, al quale gli angeli \nporgono i frutti dell’albero della vita e della conoscenza.Anche il poetico paesaggio sullo sfondo è costellato \ndi edifici, animali, santi, come Antonio abate, ritratto mentre scende le scale per andare incontro a un \ncentauro che lo condurrà attraverso il deserto della Tebaide dall’Eremita Paolo. Niente è casuale e ogni\nelemento della composizione contribuiva armonicamente a spiegare un pensiero complesso che rimane per \nnoi misterioso.Resta invece la magia di quest’opera di Giovanni Bellini dove un paesaggio assai verosimile,\ndiventa protagonista, introducendo un genere, la pittura di paesaggio, che a Venezia, a partire dal secolo \nseguente, avrà i suoi più alti raggiungimenti.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "One of the most enigmatic and fascinating works of the Renaissance, it shows the Madonna on the throne, \non the left, and a group of saints and cherubs above a large terrace overlooking a stretch of water, in \nfront of a rocky landscape.Jesus, also remembered by the representation of the cross erected in the \nlandscape on the right, is perhaps the child sitting on the cushion in the center of the composition, to whom \nthe angels bear the fruits of the tree of life and knowledge.the poetic landscape in the background is also \ndotted with buildings, animals, saints, like Anthony the Abbot, portrayed as he descends the stairs to meet a \ncentaur who will lead him through the desert of Thebaid by the Hermit Paul. Nothing is accidental and every \nelement of the composition contributed harmoniously to explain a complex thought that remains mysterious for \nus, while the magic of this work by Giovanni Bellini remains, where a very likely landscape becomes the \nprotagonist, introducing a genre, landscape painting, which in Venice, starting from the following \ncentury, will have its highest achievements";
                    }
                }
            }
        }
    }
}
