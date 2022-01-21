using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_lip : MonoBehaviour
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
                        testo.text = "E’ l’opera più celebre di Filippo Lippi, caratterizzata dalla straordinaria spontaneità della \nrappresentazione.La Madonna siede su un trono di cui si intravede solo il morbido cuscino \nricamato e il bracciolo intagliato, intenta a contemplare il figlio verso il quale rivolge un gesto \ndi preghiera.L’espressione è dolce e indulgente, ma quasi malinconica, come se la madre \npresagisse il doloroso destino del figlio.Il piccolo Gesù, coperto solo dalle fasce, risponde allo \nsguardo di Maria e protende le braccia verso di lei, sostenuto da due angeli. Quello in primo \npiano rivolge lo sguardo all’esterno, a coinvolgere lo spettatore, con volto sorridente. Il taglio \nravvicinato, con le figure poco più che a mezzo busto raccolte nell’esiguo spazio delimitato dalla \ncornice in pietra serena, rende la composizione simile a numerosi rilievi scultorei eseguiti dagli scultori \nfiorentini coevi di Filippo Lippi. La finestra si apre davanti a un vasto e vario paesaggio affacciato sul \nmare, con rocce, vegetazione, edifici.L’immagine sacra è tradotta con profonda umanità, conferita \nsia dall’espressione degli affetti che dalla scelta delle vesti e delle acconciature, ispirate alla moda \ncoeva: raffinatissima quella della Vergine, con una coroncina di perle e veli intrecciati ai capelli, \ncome le nobildonne fiorentine del secondo Quattrocento. Le aureole sono appena accennate, sottili \ncerchi e raggi di luce che non coprono il paesaggio retrostante. Non ha finora trovato conferma \nl’ipotesi che il volto della Vergine sia quella di Lucrezia Buti, la giovane monaca pratese che divenne \nmoglie di Filippo Lippi.La composizione ebbe fin da subito grande successo e fu presa a modello \nda molti artisti, fra i quali il giovane Botticelli, allievo del frate pittore. Non sappiamo tuttavia quale \nfosse l’originaria destinazione di questa immagine sacra; le prime notizie note risalgono alla fine del \nXVIII secolo, quando si trovava nella Villa medicea del Poggio Imperiale a Firenze.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "The Madonna sits on a throne of which only the soft embroidered cushion and the carved armrest \ncan be glimpsed, intent on contemplating her son to whom she turns a gesture of prayer.The \nexpression is sweet and indulgent, but almost melancholic, as if the mother foreshadowed the painful \nfate of her son. the little Jesus, covered only by the headbands, responds to the gaze \nof Mary and extends his arms towards her, supported by two angels. The one in the foreground looks \noutwards, to involve the viewer, with a smiling face. The close cut, with the little more than \nhalf-length figures gathered in the small space delimited by the stone frame, makes the composition \nsimilar to numerous sculptural reliefs made by the Florentine sculptors of Filippo Lippi's time. \nThe window opens onto a vast and varied landscape overlooking the sea, with rocks, vegetation and buildings. \nThe sacred image is translated with profound humanity, conferred by both the expression of affection and \nthe choice of clothes and hairstyles, inspired by contemporary fashion: the most refined is that \nof the Virgin, with a crown of pearls and veils woven into her hair, just like the Florentine noblewomen of \nthe second half of the fifteenth century. The haloes are just hinted at, thin circles and rays of light \nthat do not cover the landscape behind. The hypothesis that the face of the Virgin Mary is that \nof Lucrezia Buti, the young nun from Prato who became the wife of Filippo Lippi, has not yet \nbeen confirmed. However, we do not know what the original destination of this sacred image was; the first \nknown information dates back to the end of the 18th century, when it was in the Medici Villa of \nPoggio Imperiale in Florence";
                    }
                }
            }
        }
    }
}
