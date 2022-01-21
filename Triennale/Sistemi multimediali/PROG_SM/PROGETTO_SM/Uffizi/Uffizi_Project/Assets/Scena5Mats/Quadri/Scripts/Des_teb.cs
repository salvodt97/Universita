using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_teb : MonoBehaviour
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
                    if (variabile.italiano == true)
                    {
                        testo.text = "Si indica con il termine Tebaide la raffigurazione di un paesaggio roccioso in cui alcuni monaci sono intenti \nin varie attività connesse con la vita di preghiera e ascetismo. Il tema era derivato da raccolte di testi con\nle vite dei santi padri nel deserto, in cui si narravano le storie dei monaci che nei primi secoli del cristianesimo \nsi ritirarono nel deserto intorno alla città egiziana di Tebe per pregare e vivere come asceti.Questo tema ebbe\nparticolare fortuna a Firenze nel XV secolo, dove venne raffigurato su tavole di formato rettangolare, di cui il\ndipinto degli Uffizi costituisce oggi l’unico esemplare rimasto integro. Nel paesaggio numerosi episodi della \nvita leggendaria di diversi santi, fra i quali Onofrio e Antonio per esempio il religioso che attinge l’acqua dal\npozzo, quello a dorso di un cervo, il gruppo che trasporta un anziano su una barella - che delineano il percorso di\nascesi compiuto dai monaci.Il paesaggio, dominato da un fiume che sfocia al mare, è rigoglioso, pieno di alberi,\nmetafora del giardino spirituale in cui fioriscono gli asceti, esempi di virtù. Il dipinto sottintende una forte spiritualità\ne l’origine di queste figurazioni è da ricercare nell’ambiente colto del monachesimo fiorentino, sebbene\nfossero molto apprezzate anche dai laici, tanto che i Medici ne possedevano due esemplari.  ";
                    }
                    else if (variabile.inglese == true)
                    {
                        testo.text = "The term Thebaid refers to the representation of a rocky landscape in which some monks are intent on various \nactivities related to the life of prayer and asceticism. The theme was derived from collections of texts with the \nlives of the holy fathers in the desert, which told the stories of the monks who in the early centuries of Christianity \nretired to the desert around the Egyptian city of Thebes to pray and live ascetics. this theme had particular \nfortune in Florence in the fifteenth century, where it was depicted on rectangular plates, of which the \npainting of the Uffizi is now the only specimen remained intact. In the landscape many episodes of the legendary \nlife of different saints, including Onofrio and Antonio for example the religious who draws water from the well, \nthe one on the back of a deer, the group carrying an old man on a stretcher - which outline the path of asceticism made \nby the monks The landscape, dominated by a river that flows into the sea, is lush, full of trees, a metaphor \nfor the spiritual garden where the ascetics bloom, examples of virtue. The painting implies a strong spirituality and the origin \nof these figures is to be found in the cultured environment of Florentine monasticism, although they \nwere also much appreciated by the laity, so much so that the Medici owned two examples."; 
                    }
                }
            }
        }
    }
}
