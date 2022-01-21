using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_ma8 : MonoBehaviour
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
                        testo.text = "La Madonna col Bambino, che emerge da un ampio panneggio celeste straordinariamente gonfio e arioso,\nè il fulcro geometrico di questa pala d’altare.È assisa su dei gradini in posizione rialzata, sotto una loggia \nsorretta da colonne tuscaniche e con il soffitto a cassettoni, ed è circondata da otto figure maschili: \nquelle alle sue spalle e alla sua sinistra restano nell’ombra della struttura architettonica, in controluce\nrispetto alla luminosità dello sfondo, dove una quinta architettonica di edifici classici, medievali e di altre\nepoche, è dominata da un cielo celeste come il manto di Maria. Il processo creativo della tavola, concepita in \nuna struttura architettonica inusuale, dev’essere stato caratterizzato da una continua ridefinizione della\ncomposizione in corso d’opera: sono infatti visibili a distanza ravvicinata molti pentimenti. Recentemente è\nstata formulata l’ipotesi più convincente sulla sua provenienza, finora ignota.Potrebbe infatti essere\npervenuta ai Trivulzio, dopo vari passaggi, dalla chiesa del convento della Santissima Annunciata a Lacchiarella\n(Milano), convento francescano maschile della congregazione degli amadeiti, detto di San Martino. Questa intitolazione \npotrebbe aiutare a identificare i personaggi intorno alla Vergine: il giovane barbuto con una camicia bianca e un’ampia \ntunica verde, che guarda il Bambino, potrebbe essere il mecenate, forse Giovanni del Conte, membro di una famiglia molto \nlegata al convento, che fece testamento nel 1513; la figura a destra che brandisce una lunghissima spada potrebbe essere,\ninvece di san Paolo come supposto in precedenza, il santo titolare della chiesa, san Martino di Tours, cui sarebbe aggregato \nil povero, inginocchiato in primo piano con la schiena rivolta allo spettatore, in atto di adorare la Madonna.Alla sua sinistra \nsi riconosce san Giovanni Battista, inginocchiato e rivolto verso chi guarda; la sua presenza potrebbe esser riferita al committente. \nAlle spalle di Maria, a destra, con flagello e pastorale, si trova sant’Ambrogio, in una prima versione era stato effigiato con la mitra \nvescovile, poi eliminata.Alla sinistra del Bambino sono identificabili San Gerolamo eremita, con la barba bianca, colto nell’atto di \npercuotersi il petto nudo con un sasso in segno di penitenza, e forse san Giuseppe, con le mani incrociate sul petto.La pala è tra le \npiù riuscite di questo pittore, che ha elaborato una sua maniera molto personale dopo essersi formato a Milano con l’architetto e pittore \nurbinate Donato Bramante. Da confronti stilistici, la tavola si colloca tra le opere mature della produzione pittorica del Bramantino, \nnella prima metà del secondo decennio del Cinquecento, seguendo di qualche anno la Madonna col Bambino e due angeli, ora a Brera, \ndipinta dal pittore poco dopo il suo ritorno da un viaggio a Roma nel 1508.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "The Madonna and Child, which emerges from a large, extraordinarily swollen and airy celestial drapery, \nis the geometric fulcrum of this altarpiece, seated on steps in a raised position, under a loggia supported by \nTuscan columns and with a coffered ceiling, and is surrounded by eight male figures: The figures behind \nand to the left remain in the shadow of the architectural structure, against the light of the background, \nwhere an architectural backdrop of classical, medieval and other buildings is dominated by a sky as blue as Mary's \nmantle. The creative process of the table, conceived in an unusual architectural structure, must have been \ncharacterized by a continuous redefinition of the composition in progress: in fact, many regrets are visible \nat close range. Recently, the most convincing hypothesis has been formulated on its origin, which has not \nbeen known until now, and it could have been received by the Trivulzio, after several passages, from \nthe church of the convent of the Santissima Annunciata in Lacchiarella (Milan), a Franciscan male convent of the \nAmadeiti congregation, known as the San Martino convent. This title could help to identify the characters around the \nVirgin: the young bearded man with a white shirt and a large green tunic, who looks at the Child, could be the patron, \nperhaps Giovanni del Conte, a member of a family very close to the convent, who made a will in 1513; the figure on the right \nwielding a very long sword could be, instead of Saint Paul as previously assumed, the titular saint of the church, Saint \nMartin of Tours, to whom the poor would be aggregated, kneeling in the foreground with his back turned to the viewer, in \nthe act of worshipping the Madonna.On his left you can recognize St. John the Baptist, kneeling and facing the viewer, his presence \ncould be related to the client. Behind Mary, on the right, with scourge and crosier, there is Saint Ambrose, in a first version he \nwas portrayed with a machine gun, then eliminated; to the left of the Child we can identify Saint Jerome the Hermit, with a white beard, \ncaught in the act of hitting his naked chest with a stone as a sign of penance, and perhaps Saint Joseph, with his hands crossed over \nhis chest.The altarpiece is one of the most successful of this painter, who has developed his own very personal way after training in \nMilan with the architect and painter \n Urbinate Donato Bramante. From stylistic comparisons, the panel is placed among the mature works \nof the pictorial production of Bramantino, in the first half of the second decade of the sixteenth century, following a few years the \nMadonna and Child with Two Angels, now in Brera, \n painted by the painter shortly after his return from a trip to Rome in 1508";
                    }
                }
            }
        }
    }
}
