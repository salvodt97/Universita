using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_ba : MonoBehaviour
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
                        testo.text = "Il dipinto si inserisce nella serie giovanile delle mezze figure dipinte in chiaro che annovera\nopere come il Fruttaiolo della Galleria Borghese di Roma, il Fanciullo morso dal ramarro\ndella Fondazione Longhi di Firenze, il Canestro di frutta della Pinacoteca Ambrosiana di Milano. \nCaravaggio, protagonista a Roma nella prima decade del Seicento di una rivoluzione in pittura che\ninvase l’Europa intera, ostenta in quest’opera una magistrale resa naturalistica del mondo\nvegetale.Sorprendente la resa del cesto di frutta e della coppa di vino offerto dal Dio , brani intesi \nda alcuni studiosi come invito oraziano alla vita frugale, alla convivialità e all'amicizia. La scultorea \nfigura di Bacco, dall’espressione stordita dal vino è esemplata su modelli dell’arte classica, \nin particolare in ritratti di Antinoo, e appare intrisa di una sensualità languida.Mina Gregori vi \nha letto una particolare visione dell’antichità inneggiante alla libertà dei sensi ed un riferimento ai \nriti iniziatici ed ai travestimenti bacchici che si praticavano a Roma. Rinvenuta nei depositi degli Uffizi\nnel 1913 e attribuita al Caravaggio da Roberto Longhi, l'opera è da riferirsi all’attività ancora giovanile\n del pittore, quando, a Roma, si trovava sotto la protezione del cardinale Francesco Maria del Monte. \nQuesto dipinto, assieme alla Medusa), venne donato dal Cardinal del Monte a \nFerdinando I de' Medici in occasione della celebrazione delle nozze del figlio Cosimo II nel 1608.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "The painting is part of the early series of half-figures painted in clear, which includes works \nsuch as the Fruttaiolo of the Galleria Borghese in Rome, the Fanciullo morso dal ramarro \nof the Fondazione Longhi in Florence, the Canestro di frutta of the Pinacoteca Ambrosiana in Milan. \nCaravaggio, protagonist in Rome in the first decade of the seventeenth century of a revolution \nin painting that invaded the whole of Europe, shows in this work a masterful naturalistic \nrendering of the plant world, surprising the yield of the basket of fruit and the cup of wine offered \nby God, passages understood by some scholars as an invitation from Opatija to life frugal, conviviality \nand friendship. The sculptural figure of Bacchus, with his expression stunned by wine, is exemplary \non models of classical art, in particular in portraits of Antinous, and appears to be imbued with \na languid sensuality. Mina Gregori has read a particular vision of antiquity, exalting the freedom of \nthe senses and a reference to the initiation rites and bacchic disguises practiced in Rome. Found in the \ndeposits of the Uffizi in 1913 and attributed to Caravaggio by Roberto Longhi, the work refers to the still \nyouthful activity of the painter, when, in Rome, he was under the protection of Cardinal Francesco Maria \ndel Monte. This painting, together with the Medusa, was donated by Cardinal \ndel Monte to Ferdinando I de' Medici on the occasion of the celebration of the wedding of his son \nCosimo II in 1608";
                    }
                }
            }
        }
    }
}
