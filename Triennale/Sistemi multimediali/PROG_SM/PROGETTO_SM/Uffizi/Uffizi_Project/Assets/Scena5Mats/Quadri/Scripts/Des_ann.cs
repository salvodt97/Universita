using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_ann : MonoBehaviour
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
                        testo.text = "Davanti ad un palazzo rinascimentale, in un rigoglioso giardino recintato che evoca l’hortus \nconclusus allusivo alla purezza di Maria, l’Arcangelo Gabriele si inginocchia davanti alla Vergine \nrivolgendole il saluto ed offrendole un giglio. La Vergine risponde, seduta con grande dignità davanti a un \nleggio sul quale è poggiato un libro. Il tradizionale tema sacro è collocato da Leonardo in un’ambientazione\nnaturalistica e terrena: l’angelo ha una corporeità concreta, suggerita dall’ombra proiettata sul prato e \ndalla resa dei panneggi che presuppongono studi dal vero. Anche le sue ali prendono ispirazione da quelle di \nqualche poderoso rapace. E’ straordinaria la resa della luce crepuscolare che plasma le forme, unifica la scena \ne fa risaltare le sagome scure degli alberi sul lontano paesaggio dello sfondo, dominato dai toni sfumati cari\nall’artista.Gli elementi architettonici sono disegnati secondo le regole della prospettiva con punto di fuga\ncentrale, ma alcune anomalie riscontrabili nella figura della Vergine, il cui braccio destro appare eccessivamente\nlungo, potrebbero rispecchiare precoci ricerche di ottica da parte di Leonardo, che avrebbe tenuto conto del punto \ndi vista laterale(da destra) e ribassato determinato dalla collocazione originale della tavola dipinta, cioè sopra \nun altare laterale di una chiesa.Pervenuto agli Uffizi nel 1867 dalla sagrestia della chiesa di San Bartolomeo \na Monteoliveto fuori porta San Frediano a Firenze, del dipinto non si conoscono né la collocazione originaria, né \nla committenza.L’Annunciazione è largamente ritenuta un’opera giovanile di Leonardo da Vinci, eseguita \nquando il maestro era ancora nella bottega di Andrea del Verrocchio. Imita un’invenzione del Verrocchio la \nfoggia del leggio, ispirata al sarcofago di Piero il Gottoso nella chiesa di San Lorenzo a Firenze.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "In front of a Renaissance palace, in a lush fenced garden that evokes the hortus conclusus \nallusive to the purity of Mary, the Archangel Gabriel kneels before the Virgin greeting her and offering \nher a lily. The Virgin responds, seated with great dignity in front of a lectern on which is placed a book. \nThe traditional sacred theme is placed by Leonardo in a naturalistic and earthly setting: the angel has a \nconcrete corporeity, suggested by the shadow projected on the lawn and by the rendering of the drapery that \npresupposes studies from life. His wings also take inspiration from those of some mighty birds of prey. \nThe rendering of the twilight light that shapes the forms is extraordinary, it unifies the scene and brings out \nthe dark silhouettes of the trees against the distant landscape of the background, dominated by the shaded tones \ndear to the artist. The architectural elements are designed according to the rules of perspective with a \ncentral vanishing point, but some anomalies found in the figure of the Virgin, whose right arm appears excessively \nlong, could reflect early research into optics by Leonardo, who would have taken into account the lateral point of \nview (from the right) and lowered determined by the original location of the painted panel, that is, above a side \naltar of a church.The Annunciation, which reached the Uffizi in 1867 from the sacristy of the church of San Bartolomeo \nin Monteoliveto outside Porta San Frediano in Florence, is widely considered to be a youthful work by Leonardo \nda Vinci, executed when the master was still in the workshop of Andrea del Verrocchio. The shape of the \nlectern imitates an invention by Verrocchio, inspired by the sarcophagus of Piero il Gottoso in the church \nof San Lorenzo in Florence";
                    }
                }
            }
        }
    }
}
