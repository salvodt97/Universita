using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_gat : MonoBehaviour
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
                        testo.text = "Il giovane cavaliere dall’aria fiera sostiene con una mano la magnifica elsa dello spadone \ne con l’altra indica la celata, gli speroni e la mazza, ovvero i componenti dell’armatura, \nraffigurati sul parapetto in primissimo piano. Alle sue spalle uno scudiero, ritratto di profilo, regge \nl’asta dello stendardo e porta la barbozza, altro importante elemento dell’equipaggiamento di un\ncondottiero.Proveniente dalle collezioni imperiali del Castello di Praga, l’opera fu esposta per tutto \nil XVIII secolo nel Palazzo del Belvedere di Vienna con la corretta attribuzione a Giorgione e \nl’identificazione del guerriero con Erasmo da Narni(1370 - 1443), detto il Gattamelata, e quella \ndello scudiero con il figlio Antonio.Pervenuto a Firenze in seguito allo scambio di dipinti che si svolse negli \nanni tra il 1792 e il 1821 tra le collezioni imperiali di Vienna e le gallerie granducali fiorentine, il Ritratto \ndi guerriero andò ad arricchire le raccolte della Galleria degli Uffizi.La tela sembra risalire ai primissimi anni \ndel Cinquecento, trovando la sua migliore collocazione nella stagione intensamente sperimentale che \ncaratterizzò l’avvio della pittura moderna in laguna, stimolata dal soggiorno di Leonardo a Venezia nel 1500.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "The young knight with a proud air holds with one hand the magnificent hilt of the sword and \nwith the other indicates the concealed, the spurs and the bat, or the components of the armor, \ndepicted on the parapet in the foreground. From the imperial collections of Prague Castle, the work \nwas exhibited throughout the eighteenth century in the Belvedere Palace in Vienna with the correct \nattribution to Giorgione and the identification of the warrior with Erasmus of Narni (1370 - 1443), \ncalled the Gattamelata, and that of the squire with his son Anthony.The Portrait of a Warrior, \nwhich arrived in Florence after the exchange of paintings that took place between 1792 and 1821 \nbetween the imperial collections of Vienna and the Grand Duke's galleries in Florence, enriched the collections \nof the Uffizi Gallery. the canvas seems to date back to the early sixteenth century, finding its best place in the \nintensely experimental period that characterized the beginning of modern painting in the lagoon, stimulated by \nLeonardo's stay in Venice in 1500";
                    }
                }
               
            }
        }
    }
}
