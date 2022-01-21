using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_la : MonoBehaviour
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
                        testo.text = "È giorno di fiera sulla collina di Poggio a Caiano e tra i mercanti di bestiame e i \nvenditori di terraglie si aggira affaccendato in valutazioni, acquisti e trattative un popolo \ndi villani.Sulla folla indistinta si erge un personaggio, in piedi su un tavolato da \nsaltimbanco, che mostra al pubblico con ostentazione un dente appena estratto; sulla \ndestra compare un uomo di chiesa in abito nero, la guancia gonfia e il fazzoletto \nbianco in mano, simile nella cromia alla mucca pezzata, collocata al centro in primo \npiano, alla quale un contadino vuole esaminare il morso.Secondo le fonti antiche molti \ncontemporanei si riconobbero nel dipinto, apparentemente solo una scena di genere vicina \nalla pittura olandese o fiamminga molto apprezzata a corte, ma che in realtà rappresenta \nanche un ritratto in burla del popolano Antonio Morosini detto lo Scema che si finge \ncavadenti ai danni del pievano di Poggio. L’inquadratura è teatrale, impostata sulla diagonale \ntipica delle scenografie barocche, con l’architettura di campagna tracciata veloce, in colori \nliquidi, come su un tendone da fondale, mentre la luce, a sprazzi, si concentra solo su alcune figure \ne dettagli.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "It is a day of fair on the hill of Poggio a Caiano and between the cattle merchants \nand the earthenware sellers is busy in valuations, purchases and negotiations a people of villains.\nOn the indistinct crowd stands a character, standing on a board of a acrobat, who \nshows the public with ostentation a tooth just extracted, on the right appears a man \nof the church in black dress, the cheek swollen and white handkerchief in his hand, \nsimilar in color to the cow spotted, placed in the center in the foreground, which \na farmer wants to examine the bite.According to ancient sources, many contemporaries \nrecognized themselves in the painting, apparently only a genre scene close to Dutch or Flemish \npainting, much appreciated at court, but which in reality also represents a mock portrait \nof the commoner Antonio Morosini, known as the Sheikh, who pretends to be pretending \nto have teeth against the parish priest of Poggio. The shot is theatrical, set on the diagonal, \ntypical of baroque sets, with the country architecture traced quickly, in liquid colours, \nlike on a backdrop tent, while the light, in flashes, focuses only on some figures";
                    }
                }
            }
        }
    }
}
