using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Desc_duc : MonoBehaviour
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
                        testo.text = "Fra i più celebri ritratti del Rinascimento italiano, il dittico raffigura i signori di Urbino,\nFederico da Montefeltro(1422 - 1482) e sua moglie Battista Sforza(1446 - 1472).In accordo\ncon la tradizione quattrocentesca, ispirata alla numismatica antica, le due figure sono\nrappresentate di profilo, taglio che garantiva una notevole verosimiglianza e precisione nella resa\ndei particolari, senza che trasparissero gli stati d’animo: i duchi di Urbino appaiono infatti immuni\nda turbamenti e emozioni.I coniugi sono affrontati e l’unità spaziale è suggerita dalla luce e\ndalla continuità del paesaggio collinare sullo sfondo – il paesaggio marchigiano su cui i Montefeltro \nregnavano.Spicca il contrasto cromatico fra l’incarnato abbronzato di Federico e quello chiarissimo\ndi Battista Sforza, pallore che, oltre a rispettare le convenzioni estetiche in voga nel Rinascimento,\npotrebbe alludere alla precoce scomparsa della duchessa, morta giovanissima nel 1472.Sul retro delle \ntavole, i duchi sono effigiati mentre vengono portati in trionfo su carri, accompagnati dalla Virtù\ncristiane; le iscrizioni latine inneggiano ai valori morali della coppia.La presenza delle pitture sul \nverso induce a ritenere che i due dipinti, ora inseriti in una cornice moderna, potessero costituire \nin origine un dittico.Opera tra le più famose di Piero della Francesca, il doppio ritratto si inserisce \nnell’ambito di consolidato rapporto fra il pittore e i duchi di Montefeltro, alla cui corte Piero soggiornò \nripetutamente, trovandosi a contatto con un ambiente colto, raffinato, che in breve tempo \ndivenne uno dei più importanti centri culturali e artistici italiani.Il maestro concilia la rigorosa \nimpostazione prospettica appresa durante la formazione fiorentina con la lenticolare rappresentazione \ndella natura propria della pittura fiamminga, raggiungendo risultati di straordinaria e ineguagliata originalità.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Among the most famous portraits of the Italian Renaissance, the diptych depicts the lords of Urbino, \nFederico da Montefeltro (1422 - 1482) and his wife Battista Sforza (1446 - 1472).In \naccordance with fifteenth-century tradition, inspired by ancient numismatics, the two \nfigures are represented in profile, a cut that guaranteed a remarkable verisimilitude and precision \nin the rendering of details, without revealing the moods: the dukes of Urbino appear immune from \ndisturbances and emotions.The couple are faced and the spatial unity is suggested by the light and \nthe continuity of the hilly landscape in the background - the landscape of the Marches on which the \nMontefeltro reigned. The chromatic contrast between the tanned complexion of Federico and the very \nclear one of Battista Sforza stands out, a paleness that, in addition to respecting the aesthetic conventions\nin vogue in the Renaissance, could allude to the early death of the duchess, who died very young \nin 1472.On the back of the panels, the dukes are depicted as they are carried in triumph on \nchariots, accompanied by Christian Virtue; the Latin inscriptions praise the moral values of the couple. \nThe presence of the paintings on the verse leads us to believe that the two paintings, now placed in a \nmodern frame, could have been originally a diptych.One of the most famous works by Piero della Francesca, \nthe double portrait is part of the consolidated relationship between the painter and the dukes of Montefeltro, \nat whose court Piero stayed repeatedly, finding himself in contact with a cultured, \nrefined environment, which in a short time  became one of the most important cultural and artistic \ncenters in Italy.The master reconciles the rigorous perspective approach learned during his training in \nFlorence with the lenticular representation of the nature of Flemish painting, achieving results of extraordinary \nand unparalleled originality";
                    }
                }
            }
        }
    }
}
