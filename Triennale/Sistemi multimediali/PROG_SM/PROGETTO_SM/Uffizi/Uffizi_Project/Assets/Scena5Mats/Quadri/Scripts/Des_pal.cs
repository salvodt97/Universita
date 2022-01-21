using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_pal : MonoBehaviour
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
                        testo.text = "Come gli altri dipinti di soggetto mitologico di Botticelli, anche quest’opera, raffigurante una giovane donna \narmata di un’ascia da battaglia e intenta a trattenere per i capelli un centauro, presenta molti dubbi di interpretazione.\nSulla base delle citazioni in inventari e fonti letterarie di poco successive alla realizzazione del dipinto, si tende a\nriconoscere nella avvenente e fiera figura femminile Minerva, dea della sapienza, oppure Camilla, vergine guerriera \nperita in battaglia per difendere la patria ed esempio di castità.Il centauro, creatura mitologica dove l’uomo si fonde con \nla bestia, simboleggia gli istinti ferini dell’umanità, pertanto l’opera è da intendersi come un’allegoria della virtù che frena \nil temperamento sanguigno e passionale.La giovane donna indossa una veste ornata ripetutamente dal motivo dell’anello \ndi diamante corrispondente all’impresa adottata da diversi componenti di casa Medici. La sua figura è avvolta da tralci\nvegetali, forse l’olivo consacrato a Minerva oppure il mirto, pianta associata a Camilla. Ai Medici, e precisamente a\nLorenzo di Pierfrancesco, cugino di Lorenzo il Magnifico, apparteneva il dipinto e potrebbe essere stato commissionato \nin occasione del suo matrimonio con Semiramide Appiani, nel 1482.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Like the other mythological paintings by Botticelli, this work, depicting a young woman armed with a battle axe \nand intent on holding a centaur by the hair, presents many doubts of interpretation. On the basis of quotations in inventories \nand literary sources shortly after the painting was made, we tend to recognize in the attractive and proud female \nfigure Minerva, goddess of wisdom, or Camilla, virgin warrior perished in battle to defend the country and example of \nchastity.The centaur, a mythological creature where man merges with the beast, symbolizes the ferocious instincts of mankind, \nso the work is intended as an allegory of virtue that curbs blood temperament and passion, the young woman wearing a dress \nrepeatedly decorated with the motif of the diamond ring corresponding to the undertaking adopted by different members of \nthe Medici family. Her figure is wrapped in vegetable shoots, perhaps the olive tree consecrated to Minerva or the myrtle, \na plant associated with Camilla. The painting belonged to the Medici, namely to Lorenzo di Pierfrancesco, Lorenzo \nthe Magnificent's cousin, and may have been commissioned on the occasion of his marriage to Semiramide Appiani in 1482";
                    }
                }
            }
        }
    }
}
