using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_fl : MonoBehaviour
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
                        testo.text = "La giovane donna emerge dal fondo bruno del dipinto porgendo con la mano destra un mazzo di fiori \nprimaverili, composto di roselline, viole, gelsomini; è abbigliata all’antica, con una candida camiciola che \nscivola sulla spalla destra lasciando intravedere il seno, mentre reclina dolcemente la testa sulla spalla \nsinistra, volgendo lo sguardo fuori dallo spazio dipinto. Il suo volto, dai tratti delicatissimi, corrisponde\nperfettamente ai canoni della bellezza rinascimentale cinquecentesca: pelle chiara e luminosa, il rosa \nsulle guance, e il viso incorniciato da lunghi capelli sciolti, biondo ramati, il colore tipico delle chiome delle \ndonne ritratte da Tiziano(da qui il termine rosso Tiziano).L’identificazione del soggetto come Flora, la \nninfa sposa di Zefiro di origine greca le cui gesta sono narrate da Ovidio, risale a Joachim von Sandrart,\nstoriografo olandese, che nel 1635 circa vide l’opera nella collezione di don Alfonso Lòpez, ambasciatore spagnolo \nad Amsterdam.Venduta da quest’ultimo all’Arciduca Leopoldo Guglielmo d’Asburgo, la tela giunse poi \na Firenze nel 1793 nell’ambito degli scambi di opere d’arte tra l’Imperiale Galleria del Belvedere di Vienna e \ni granduchi di Toscana.La celebrità di questa immagine è testimoniata dalle numerose incisioni tratte a partire \ndal XVI secolo.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "The young woman emerges from the brown background of the painting offering with her right hand a \nbouquet of spring flowers, composed of roses, violets, jasmines; she is dressed in the old style, with a white \nblouse that slips on the right shoulder allowing a glimpse of the breast, while gently reclining her head \non the left shoulder, looking out of the painted space. His face, with its very delicate features, perfectly \ncorresponds to the canons of Renaissance beauty of the sixteenth century: light and bright skin, pink on \nthe cheeks, and the face framed by long loose hair, blond copper, the typical color of the foliage of women portrayed \nby Titian (hence the term red Titian).The identification of the subject as Flora, the nymph bride of \nZephyrus of Greek origin whose deeds are narrated by Ovid, dates back to Joachim von Sandrart, a Dutch \nhistorian, who in about 1635 saw the work in the collection of Don Alfonso Lòpez, Spanish ambassador to Amsterdam.Sold \nby the latter to Archduke Leopold William of Hapsburg, the canvas then arrived in Florence in 1793 \nas part of the exchange of works of art between the Imperial Gallery of the Belvedere in Vienna and the Grand \nDukes of Tuscany, the celebrity of this image is evidenced by the numerous engravings taken from the sixteenth \ncentury";
                    }
                }
            }
        }
    }
}
