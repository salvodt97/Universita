using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_sa : MonoBehaviour
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
                        testo.text = "Il dipinto illustra il passo dell’Antico Testamento in cui Dio sottopose Abramo a una straordinaria prova \ndi obbedienza ordinandogli il sacrificio del suo unico figlio Isacco. Caravaggio raffigura in modo fedele il \nmomento cruciale del drammatico racconto, ovvero quando il vecchio Abramo, nell’attimo in cui sta \nper immolare Isacco, viene bloccato dall’angelo inviato dal Signore. Caravaggio sceglie di umanizzare la figura\ndell’angelo affiancandola ad Abramo come una solida presenza che afferra il polso del vecchio con una forte e\nconcreta presa. Sullo sfondo si apre un paesaggio collinare disteso e mediterraneo percorso da viottoli e animato da \ncasolari e da un borgo. In questo paesaggio sono stati individuati dalla critica echi di stile della formazione di Caravaggio \nin Lombardia e Veneto. Di quest’opera è stata data in passato anche una lettura simbolica secondo la quale l’edificio posto \nsulla collina sarebbe una chiesa con battistero, riferimento alla futura nascita della chiesa cattolica, e la luce diffusa sul \npaesaggio simbolizzerebbe la luce della grazia divina. Il sacrificio del giovane Isacco andrebbe dunque a prefigurare il sacrificio \ndi Cristo. Il tema biblico venne certamente indicato dall’illustre committente dell’opera, Maffeo Barberini, influente monsignore \ndella curia vaticana al tempo dell’esecuzione del dipinto, e futuro papa col nome di Urbano VIII. La paternità di Caravaggio per \nquesto dipinto, da tempo riconosciuta da tutta la critica, è testimoniata anche da pagamenti effettuati da Maffeo Barberini al pittore stesso. ";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "The painting illustrates the passage from the Old Testament in which God subjected Abraham to an extraordinary \ntrial of obedience by ordering him to sacrifice his only son Isaac. Caravaggio faithfully depicts the crucial \nmoment of the dramatic story, when the old Abraham, in the moment when he is about to sacrifice \nIsaac, is blocked by the angel sent by the Lord. Caravaggio chooses to humanize the figure of the angel by \nplacing it alongside Abraham as a solid presence that grabs the wrist of the old man with a strong and concrete \ngrip. In the background opens a hilly landscape stretched and Mediterranean path by paths and animated by \ncottages and a village. In this landscape have been identified by critics echoes of style of the formation of Caravaggio \nin Lombardy and Veneto. In the past, this work has also been given a symbolic interpretation according to which the building on the hill is \na church with a baptistery, a reference to the future birth of the Catholic church, and the light diffused over the landscape \nsymbolises the light of divine grace. The sacrifice of the young Isaac would therefore prefigure the sacrifice of Christ. The biblical \ntheme was certainly indicated by the illustrious patron of the work, Maffeo Barberini, influential monsignor \nof the Vatican Curia at the time of the execution of the painting, and future pope with the name of Urban VIII. The authorship of Caravaggio for this \npainting, long recognized by all the critics, is also testified by payments made by Maffeo Barberini to the painter himself. ";

                    }
                }
            }
        }
    }
}
