using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class desc_prim : MonoBehaviour
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
                        testo.text = "Conosciuto con il nome convenzionale di Primavera, la pittura mostra nove figure\ndella mitologia classica che incedono su un prato fiorito, davanti a un bosco di aranci\ne alloro.In primo piano a destra, Zefiro abbraccia e feconda la ninfa Clori, raffigurata\npoco oltre nelle sembianze di Flora, dea della fioritura.Dominano il centro della composizione,\nleggermente arretrati, la dea dell’amore e della bellezza Venere, castamente vestita, e Cupido, \nraffigurato bendato mentre scocca il dardo d’amore.A sinistra danzano in cerchio le tre Grazie,\ndivinità minori benefiche prossime a Venere, e chiude la composizione Mercurio, il messaggero \ndegli dei con indosso elmo e calzari alati, che sfiora col caduceo una nuvola. Pur rimanendo\nmisterioso il complesso significato della composizione, l’opera celebra l’amore, la pace, \nla prosperità.La vegetazione, il cui colore scuro è in parte dovuto all’alterazione del pigmento \noriginale, è rischiarata dall’abbondanza di fiori e frutti.Sono state riconosciute ben 138 \nspecie di piante diverse, accuratamente descritte da Botticelli servendosi forse di erbari. \nLa cura per i dettagli conferma l’impegno profuso dal maestro in quest’opera, confermato \nanche dalla perizia tecnica con cui è stata realizzata la stesura pittorica.\nRealizzata su un supporto di legno di pioppo, l’opera si trovava alla fine del XV secolo nella \ncasa in via Larga(oggi via Cavour) degli eredi di Lorenzo di Pierfrancesco de’ Medici, cugino di \nLorenzo il Magnifico; stava appeso sopra un lettuccio, una sorta di cassapanca con schienale \ncaratteristica dell’arredamento delle residenze signorili rinascimentali.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Known by the conventional name of Primavera, the painting shows nine figures of \nclassical mythology walking on a flowering meadow, in front of a forest of oranges and \nlaurel trees. in the foreground on the right, Zephyr embraces and fertilizes the nymph \nChlor, depicted just beyond in the guise of Flora, goddess of flowering.The centre of the composition \nis dominated by the goddess of love and beauty, Venus, casually dressed, and Cupid, depicted \nblindfolded while the dart of love strikes; on the left the three Graces dance in a circle, \nminor gods close to Venus, and the composition Mercury, the messenger of the gods wearing a helmet \nand winged shoes, who touches a cloud with her fall, closes. Although the complex meaning \nof the composition remains mysterious, the work celebrates love, peace and prosperity. \nThe vegetation, whose dark colour is partly due to the alteration of the original pigment, is illuminated \nby the abundance of flowers and fruits. 138 different species of plants have been \nrecognized, carefully described by Botticelli, perhaps using herbaria. The attention to detail \nconfirms the commitment of the master in this work, also confirmed by the technical skill \nwith which the painting was made.Made on a poplar wood support, the work \nwas located at the end of the fifteenth century in the house in Via Larga (now Via Cavour) of \nthe heirs of Lorenzo di Pierfrancesco de' Medici, cousin of Lorenzo the Magnificent; it was hung \nover a bed, a sort of chest with backrest characteristic of the furnishings of Renaissance \nstately homes";
                    }
                }
            }
        }
    }
}
