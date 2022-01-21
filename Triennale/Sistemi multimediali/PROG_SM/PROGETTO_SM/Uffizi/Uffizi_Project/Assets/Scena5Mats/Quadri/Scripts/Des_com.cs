using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_com : MonoBehaviour
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
                        testo.text = "In questo dipinto Giovanni Bellini torna a cimentarsi con un tema più volte affrontato nell’arco della \nsua attività:la Madonna e Giovanni evangelista siedono a terra per sorreggere il corpo di Cristo \ndeposto dalla croce.Intorno si dispongono varie figure alla cui realizzazione partecipò probabilmente \nun collaboratore di Giovanni.A destra si riconosce la figura di un monaco, anacronistico rispetto alla storia \ndi Cristo, e ciò ci fa comprendere che il dipinto non aveva carattere narrativo, bensì devozionale ed era destinato \nalla meditazione.Molto particolare la tecnica usata – una pittura monocroma – che conferisce al dipinto l’aspetto di\nun disegno preparatorio, tanto che alcuni si interrogano se in verità si tratti di un dipinto non finito. Secondo quanto riportato \nda Paolo Pino, letterato veneziano del XVI secolo, Giovanni Bellini era infatti solito eseguire con grande diligenza  i disegni \npreparatori, poi coperti dai colori.Un’idea alternativa è che possa trattarsi di un modello lasciato a disposizione della bottega \nper trarne copie da dipingere.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "In this painting Giovanni Bellini returns to engage with a theme repeatedly addressed in the course of \nhis work: the Madonna and John the Evangelist sit on the ground to support the body of Christ laid \nfrom the cross. around there are several figures whose realization probably participated in a \ncollaborator of John.On the right is the figure of a monk, anachronistic compared to the history of Christ, and this \nmakes us understand that the painting was not narrative, but devotional and was intended for meditation.very particular \ntechnique used - a monochrome painting - which gives the painting the appearance of a preparatory drawing, so \nthat some people wonder if it is actually an unfinished painting. According to Paolo Pino, a 16th century Venetian man of letters, \nGiovanni Bellini used to carry out the preparatory drawings with great diligence and then covered them with colours, an alternative \nidea being that it might be a model left at the disposal of the workshop to make copies for painting";
                    }
                }
            }
        }
    }
}
