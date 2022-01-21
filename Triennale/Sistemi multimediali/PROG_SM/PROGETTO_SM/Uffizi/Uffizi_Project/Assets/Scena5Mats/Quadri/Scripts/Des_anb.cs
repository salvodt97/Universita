using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_anb : MonoBehaviour
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
                        testo.text = "Il consueto tema dell’annuncio dell’arcangelo Gabriele alla Vergine è ambientato in un palazzo \nrinascimentale affacciato su un giardino, chiuso sul fondo dal muro di cinta merlato. Il portico, \nentro cui avviene l’apparizione dell’arcangelo Gabriele, introduce alla camera di Maria, alle cui \nspalle si erge l’alto letto ligneo circondato da cassepanche, protetto nell’intimità dal tendaggio ora \nscostato.L’ambientazione offre dunque utili informazioni sull’arredo dei palazzi signorili in voga nel \nRinascimento, del quale facevano parte anche preziosi tappeti come quello sul quale è inginocchiata \nla Vergine.La pittura è comunque ricca di riferimenti simbolici allusivi alla madre di Dio, seppure \nmascherati dietro l’aspetto di quotidianità.Il giardino chiuso da mura simboleggia la purezza di Maria, \nmentre la tenda a padiglione suggerisce un parallelismo fra Maria, che porta in grembo Gesù, e la tenda \nche conteneva l’Arca dell’alleanza.Si tende a porre in relazione l’esecuzione dell’affresco con l’attestazione \ndi un pagamento a Sandro Botticelli eseguito nel 1481, alla vigilia della partenza del pittore per Roma, dove \nlavorò alla decorazione della Cappella Sistina.La grande pittura murale si trovava in origine sotto una \nloggia antistante la chiesa di San Martino nell’ospedale di Santa Maria della Scala a Firenze, ma \nsuccessivamente alcune modifiche architettoniche apportate all’edificio nascosero parzialmente \nl’affresco.Fu quindi staccato dalla sua sede nel 1920 e restaurato.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "The usual theme of the Archangel Gabriel's announcement to the Virgin is set in a Renaissance \npalace overlooking a garden, closed at the bottom by the crenellated wall. The portico, within which \nthe apparition of the archangel Gabriel takes place, introduces the room of Mary, to whose balls \nstands the high wooden bed surrounded by chests of drawers, protected in intimacy by the now displaced \ncurtain. the setting therefore offers useful information on the furnishings of the palaces in vogue in \nthe Renaissance, which included also precious carpets such as the one on which the Virgin is kneeling. \nThe painting is still rich in symbolic references alluding to the mother of God, although masked \nbehind the appearance of everyday life. the painting is rich in allusive symbolic references to the mother \nof God, even if behind the appearance of everyday life.The garden enclosed by walls symbolises Mary's \npurity, while the pavilion curtain suggests a parallelism between Mary, who carries Jesus in her lap, and the \ncurtain that contained the Ark of the Covenant, which tends to relate the execution of the fresco to the proof \nof payment to Sandro Botticelli made in 1481, on the eve of the painter's departure for Rome, where he \nworked on the decoration of the Sistine Chapel.The large wall painting was originally located under \na loggia in front of the church of San Martino in the hospital of Santa Maria della Scala in \nFlorence, but later some architectural changes made to the building partially concealed \nthe fresco, so it was detached from its headquarters in 1920 and restored";
                    }
                }
            }
        }
    }
}
