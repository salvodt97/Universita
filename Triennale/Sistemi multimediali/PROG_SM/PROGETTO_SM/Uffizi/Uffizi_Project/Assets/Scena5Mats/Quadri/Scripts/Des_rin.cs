using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_rin : MonoBehaviour
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
                        testo.text = "L'opera apparteneva ad un ciclo di diciannove dipinti ispirati ai poemi di Ovidio, Ariosto e Tasso, \ncommissionati dal cardinale Carlo de’ Medici e destinati a ornare il suo appartamento nel Casino di San Marco.\nL’episodio raffigurato è narrato nell’ultimo canto della Gerusalemme liberata, incentrato sulla terribile \nbattaglia tra i Crociati e l’esercito egiziano nel corso della quale Rinaldo e Armida si sfidano a duello.La maga, \ndopo aver tentato invano di colpire il giovane guerriero di cui è ancora innamorata, decide di darsi la morte con \nla stessa freccia utilizzata per il combattimento. Rinaldo le afferra il braccio e 'da tergo ei le si avventa/ che già la\nfera punta al petto stende.Si volse Armida e 'l rimirò improviso, ché no 'l sentí quando da prima ei venne: \nalzò le strida, e da l'amato viso torse le luci disdegnosa e svenne'.La drammatica concitazione dei versi del \nTasso trova riscontro puntuale nella pittura di Dandini, nella quale i personaggi a grandezza naturale si \nmuovono in primo piano come evocando gli eroi di quel melodramma che sul volgere del secolo muoveva i\nsuoi primi passi a Firenze, nell’ambiente colto e raffinato della Camerata de’ Bardi.Il tono drammatico delle\nespressioni, la posa teatrale delle figure, la preziosità della materia pittorica, ricca di effetti cromatici e di luce, e \ni raffinati dettagli d’ornato, riflettono gli orientamenti dell’arte fiorentina del primo Seicento, fortemente \nispirata dalle armonie del recitar cantando.La tela giunse nelle gallerie fiorentine nel 1913, proveniente da \ncollezione privata.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "The work belonged to a cycle of nineteen paintings inspired by the poems of Ovid, Ariosto and Tasso, \ncommissioned by Cardinal Carlo de' Medici and intended to decorate his apartment in the Casino di San Marco.\nThe episode depicted is narrated in the last song of Jerusalem Freed, centered on the terrible battle between \nthe Crusaders and the Egyptian army during which Rinaldo and Armida challenge each other to a duel. the sorceress, \nafter trying in vain to hit the young warrior with whom she is still in love, decides to die with the same arrow \nused for the fight. Rinaldo grabs her arm and 'da tergo ei le si avventa/ che già la\nfera punta al petto stende.Si volse \nArmida e 'l rimirò improviso, ché no 'l sentí quando da prima ei venne: alzò le strida, e da l'amato viso \ntorse le luci disdegnosa e svenne' The dramatic excitement of the verses of Tasso is punctually reflected in \nDandini's painting, in which the life-size characters move in the foreground as evoking the heroes of that \nmelodrama that at the turn of the century moved its first steps in Florence, in the cultured and refined \nenvironment of the Camerata de' Bardi.The dramatic tone of the expressions, the theatrical pose of the \nfigures, the preciousness of the pictorial material, rich in chromatic effects and light, and the refined details of the \nornament, reflect the orientations of the Florentine art of the early seventeenth century, strongly inspired by the \nharmonies of the singing recitar. the canvas arrived in the Florentine galleries in 1913, coming from a private \ncollection";
                    }
                }
            }
        }
    }
}
