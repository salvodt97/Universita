using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_ad : MonoBehaviour
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
                        testo.text = "La composizione è talmente ricca di personaggi che si stenta a riconoscere i tre re magi giunti dall’oriente \nper rendere omaggio a Gesù bambino, davanti al quale si inginocchiano offrendo i doni preziosi contenuti \nentro vasi di raffinata fattura. Il piccolo, in grembo alla madre Maria, stringe a sé il primo omaggio, offerto \ndal re più anziano, sotto lo sguardo pensieroso del padre putativo Giuseppe. Fra i personaggi del seguito dei \nmagi, l’attenzione ricade sull’uomo inginocchiato a sinistra, che indossa una sontuosa veste gialla foderata di \npeliccia e reca con sé un astrolabio, allusivo alle conoscenze astrologiche dei magi.Si tende a \nriconoscervi il ritratto di Pierfrancesco de’ Medici(1430 - 1476), al quale evidentemente i frati agostiniani\ncanonici della chiesa di San Donato a Scopeto a Firenze, committenti dell’opera, vollero rendere omaggio.I figli di\nPierfrancesco, Lorenzo(1463 - 1503) e Giovanni(1467 - 1498) sarebbero invece da riconoscere\nrispettivamente nel re che viene incoronato e nel giovane biondo che gli sta accanto e regge il vaso.La \nscena è ambientata in un paesaggio campestre, davanti a una capanna sopra la quale splende la stella cometa che\naveva guidato i magi.Nello sfondo sono collocati scene del loro viaggio, dall’avvistamento della stella al passaggio \nper il palazzo di re Erode.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "The composition is so rich in characters that it is difficult to recognize the three wise men who came from the \nEast to pay homage to Jesus the child, before whom they kneel offering the precious gifts contained in \nvases of refined workmanship. The little one, in the lap of his mother Mary, holds the first homage to himself, \noffered by the oldest king, under the pensive gaze of his putative father Joseph. Among the characters of the \nretinue of the Magi, the attention falls on the man kneeling on the left, who wears a sumptuous yellow dress \nlined with fur and carries with him an astrolabe, allusive to the astrological knowledge of the Magi.\nThe sons of Pierfrancesco, Lorenzo (1463 - 1503) and Giovanni (1467 - 1498), on the other hand, are to be \nrecognized respectively in the king who is crowned and in the young blond who stands next to him and holds the vase; \nthe scene is set in a rural landscape, in front of a hut above which shines the comet star \nthat had guided the Magi; scenes of their journey, from the sighting of the star to the passage through \nthe palace of King Herod, are placed in the background";
                    }
                }
            }
        }
    }
}
