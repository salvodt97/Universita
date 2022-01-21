using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_batt : MonoBehaviour
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
                        testo.text = "Sulle rive del fiume Giordano, in Palestina, Gesù riceve il sacramento del battesimo da san Giovanni, \nche gli terge la testa versando dell’acqua.Il Battista sorregge un’esile croce e un cartiglio iscritto con \nl’annuncio dell’avvento del Salvatore: ECCE AGNUS DEI[QUI TOLLIT PECCATA MUNDI](Ecco l’agnello di \nDio che toglie i peccati del mondo; Vangelo di Giovanni 1, 29). Assistono all’evento due angeli inginocchiati, \nuno dei quali sorregge la veste di Gesù.Lo storiografo Giorgio Vasari, alla metà del XVI secolo, racconta \nche per l’esecuzione del dipinto Andrea del Verrocchio si avvalse della collaborazione del suo giovane \nallievo Leonardo, che eseguì con straordinaria maestria la figura dell’angelo di sinistra, tanto da indispettire \nil più anziano Verrocchio.Gli studi odierni sono orientati a ritenere che l’intervento di Leonardo sia stato più \nampio e che sia intervenuto anche nell’esecuzione del suggestivo paesaggio fluviale, su cui degrada la \nluce dorata, e della figura di Cristo.Era del resto usuale, nell’organizzazione delle officine artistiche del\nQuattrocento, che il capobottega ideasse l’opera, lasciando poi l’esecuzione di parti secondarie ad allievi e\ncollaboratori.E’ probabile che nella tavola col Battesimo di Cristo, oltre a Verrocchio e a Leonardo, abbia \nlavorato anche un altro pittore, più vecchio, come suggerisce il carattere meno evoluto di alcuni \ndettagli, quali ad esempio le mani di Dio Padre e la colomba dello Spirito Santo, in alto.L’angelo di \nLeonardo spicca invece per l’articolata posa del corpo, di cui si scorge insieme le spalle e il tenero volto \ngiovanile, come stesse voltandosi, e la straordinaria naturalezza dei panneggi del manto azzurro.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "On the banks of the Jordan River, in Palestine, Jesus receives the sacrament of baptism from Saint John, \nwho holds his head by pouring water, and the Baptist holds a slender cross and a scroll inscribed with \nthe announcement of the coming of the Saviour: ECCE AGNUS DEI[QUI TOLLIT PECCATA MUNDI](Behold the \nLamb of God who takes away the sins of the world; Gospel of John 1, 29). The historian Giorgio Vasari, in the \nmid-sixteenth century, tells that for the execution of the painting Andrea del Verrocchio availed himself of \nthe collaboration of his young pupil Leonardo, who performed with extraordinary skill the figure of \nthe angel on the left, so as to displease the older Verrocchio.Today's studies are oriented towards believing that \nLeonardo's intervention was broader and that he also intervened in the execution of the evocative river landscape, \non which the golden light falls, and of the figure of Christ.It was customary in the organization of \nthe fifteenth-century art workshops for the master of the workshop to conceive the work, leaving the execution \nof secondary parts to students and collaborators, and it is probable that another older painter worked on \nthe panel with the Baptism of Christ, in addition to Verrocchio and Leonardo, as suggested by the less evolved \ncharacter of some details, such as the hands of God the Father and the dove of the Holy Spirit, \nabove.Leonardo's angel stands out for the articulated pose of his body, of which you can see his \nshoulders and tender youthful face, as if he were turning around, and the extraordinary naturalness of the drapery \nof the blue mantle";
                    }
                }
            }
        }
    }
}
