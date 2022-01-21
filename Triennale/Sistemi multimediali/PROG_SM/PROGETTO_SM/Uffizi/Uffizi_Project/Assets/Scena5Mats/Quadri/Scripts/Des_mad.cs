using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_mad : MonoBehaviour
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
                        testo.text = "La tavola è stata dipinta durante il soggiorno di Raffaello a Firenze (1504-1508), dove poté studiare\ni grandi maestri fiorentini e dove lavorò per alcune grandi famiglie di mercanti.Nella biografia del \npittore Giorgio Vasari riferisce che questo dipinto gli fu commissionato per le nozze di Lorenzo \nNasi con Sandra di Matteo Canigiani, celebrate il 23 febbraio 1506.Quando nel 1547 casa \nNasi fu travolta da uno smottamento della collina, la tavola si schiantò in diciassette frammenti, \nraccolti e affidati probabilmente a Michele di Ridolfo del Ghirlandaio per il restauro. La sua storia \nsuccessiva è ignota fino alla sua registrazione nella collezione del Cardinal Giovan Carlo\nde’ Medici nel 1646 - 47.Negli anni fiorentini Raffaello elaborò altre varianti sul tema del gruppo \ndella Madonna col Bambino e San Giovannino, in cui riuscì a fondere le esperienze fatte fino ad allora \nfra Urbino e Firenze.La composizione piramidale riflette l’impressione profonda che l’artista riportò \ndal perduto cartone per la Madonna col Bambino e Sant’Anna di Leonardo, già esposto all’inizio del\nsecolo alla Santissima Annunziata, e dalla “Madonna col Bambino di Bruges” di Michelangelo, scolpita \nentro l’estate del 1506.Attraverso lo studio delle leggi proporzionali della natura e delle opere del \nPerugino, di Fra’ Bartolomeo e di Leonardo, Raffaello riuscì a creare immagini di una bellezza \nideale, armoniosa e perfetta nella sua semplicità, ma anche vitale e dinamica per l’intenso scambio \ndi sguardi e di gesti che legano le figure e per la varietà aggraziata delle espressioni, rese più naturali \ndallo sfumato leonardesco, impiegato anche per dissolvere il paesaggio all’orizzonte nell’atmosfera.\nIn quest’immagine così moderna restano tuttavia degli elementi simbolici della tradizione devozionale, \ncome il piccolo testo sacro che tiene in mano la Vergine, segno della sua fede e della prefigurazione del \nsacrificio di Cristo; sacrificio evocato anche dall’innocente fragilità del cardellino che San Giovannino porge \na Gesù per farglielo accarezzare.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "The panel was painted during Raphael's stay in Florence (1504-1508), where he was able to study the great \nFlorentine masters and where he worked for some great merchant families. in the biography of the \npainter Giorgio Vasari reports that this painting was commissioned for the wedding of Lorenzo \nNasi with Sandra di Matteo Canigiani, celebrated on February 23, 1506.When in 1547 the house \nNasi was overwhelmed by a landslide of the hill, the table crashed into seventeen fragments, collected \nand probably entrusted to Michele di Ridolfo del Ghirlandaio for restoration. Its history is unknown \nuntil its registration in the collection of Cardinal Giovan Carlo de' Medici in 1646 - 47. \nIn the Florentine years Raphael developed other variations on the theme of the group of the Madonna \nand Child with St. John, in which he managed to merge the experiences made until then between Urbino \nand Florence.The pyramidal composition reflects the profound impression that the artist brought back \nfrom Leonardo's lost cartoon for the Madonna with Child and St. Anne, already exhibited at the \nbeginning of the century at the Santissima Annunziata, and from Michelangelo's Madonna with Child of \nBruges, sculpted by the summer of 1506.Through the study of the proportional laws of nature and the works \nof Perugino, Fra' Bartolomeo and Leonardo, Raphael managed to create images of an ideal beauty, \nharmonious and perfect in its simplicity, but also vital and dynamic for the intense exchange of \nlooks and gestures that bind the figures and for the graceful variety of expressions, made more natural by \nthe nuanced Leonardo, also used to dissolve the landscape on the horizon in the atmosphere.In this\nmodern image, however, remain symbolic elements of the devotional tradition, the small sacred text that \nholds the Virgin in his hand, a sign of his faith and the foreshadowing of the sacrifice of Christ, a \nsacrifice also evoked by the innocent fragility of the goldfinch that St. John offers to Jesus to make him caress him";
                    }
                }
            }
        }
    }
}
