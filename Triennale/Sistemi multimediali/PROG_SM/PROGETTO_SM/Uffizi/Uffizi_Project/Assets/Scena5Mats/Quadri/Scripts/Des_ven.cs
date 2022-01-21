using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class Des_ven : MonoBehaviour
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
                        testo.text = "L’ opera è una delle più celebri di Tiziano e ritrae una figura emblematica di giovane sposa in procinto \ndi essere abbigliata per prendere parte alla celebrazione del rito noto a Venezia come il toccamano. \nSi trattava di una cerimonia a carattere domestico e non ecclesiastico durante la quale le giovani donne richieste \nin matrimonio, toccando la mano dello sposo, esprimevano il loro consenso alle nozze. Tiziano coglie lo spunto \nispirata all’antica figurazione della Venus pudica.La fanciulla, distesa nuda su un letto dalle lenzuola\nspiegazzate, guarda lo spettatore con occhi ammiccanti e allusivi, mentre con la mano sinistra nasconde il \npube e nella destra tiene un mazzolino di rose, emblema della Dea e della piacevolezza e della costanza in \namore.Ai piedi del letto il cagnolino addormentato richiama alla fedeltà coniugale.Lo sfondo mostra un ambiente \nraffinato, peculiare di una ricca casa patrizia della Venezia del Cinquecento.Vi sono affaccendate due ancelle: \nuna è intenta a frugare nel cassone istoriato dal quale ha appena estratto il sontuoso abito color oro e \nazzurro destinato alle nozze, visibile sulla spalla dell’altra ancella in piedi a destra.Sul davanzale delle finestra, \nil vaso di mirto, pianta tradizionalmente legata a Venere, costituisce un ulteriore riferimento alla costanza in \namore cui allude ancora il cagnolino ai piedi del letto.In questa tela Tiziano conferma il suo straordinario talento\nnel conferire intensità e carattere ai personaggi, nonché una sapienza ineguagliabile nel restituire la morbidezza\ndegli incarnati e le qualità dei materiali. Come attesta un lettera del 1538, il dipinto della donna nuda fu \nacquistato da Guidobaldo II della Rovere direttamente da Tiziano; la tela giunse poi a Firenze nel 1631 con \nl’eredità di Vittoria della Rovere, ultima della Casata e moglie del granduca di Toscana, Ferdinando II de’ \nMedici.Per lungo tempo fu esposta nella Tribuna degli Uffizi vicino alla Venere de’ Medici, probabilmente in \nun voluto confronto tra le due conturbanti bellezze, quella classica e ideale della statua antica e quella moderna \ne carnale dipinta da Tiziano.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "The work is one of Titian's most famous and portrays an emblematic figure of a young bride about to be \ndressed to take part in the celebration of the ritual known in Venice as the touching. It was a domestic \nand non-ecclesiastical ceremony during which the young women requested in marriage, touching the groom's hand, \nexpressed their consent to the wedding. Titian takes the inspiration inspired by the ancient figuration of the Venus \npudica. The girl, lying naked on a bed with crumpled sheets, looks at the viewer with winking and \nallusive eyes, while with her left hand she hides her pubis and right holds a bouquet of roses, emblem of the \nGoddess and of the pleasure and constancy in love.At the foot of the bed the sleeping dog recalls the conjugal \nfidelity.The background shows a refined environment, peculiar of a rich patrician house of Venice of the \nsixteenth century. Two maidservants are busy: one is intent on rummaging in the decorated chest from which she has \njust extracted the sumptuous gold and blue dress for the wedding, visible on the shoulder of the other maid \nstanding on the right. of the window, the myrtle pot, a plant traditionally linked to Venus, constitutes a further \nreference to the constancy in love to which the little dog still alludes at the foot of the bed. tiziano canvas confirms \nhis extraordinary talent in giving intensity and character to the characters, as well as an incomparable wisdom \nin restoring the softness of the incarnations and the qualities of the materials. As a letter of 1538 attests, \nthe nude woman's painting was bought by Guidobaldo II della Rovere directly from Titian; the canvas then arrived \nin Florence in 1631 with the legacy of Vittoria della Rovere, last of the House and wife of the Grand Duke \nof Tuscany, Ferdinando II de 'Medici. 'Medici, probably in a deliberate confrontation between the two disturbing \nbeauties, the classical and ideal one of the ancient statue and the modern one of the carnal painted \nby Titian.";
                    }
                 }  
            }
        }
    }
}
