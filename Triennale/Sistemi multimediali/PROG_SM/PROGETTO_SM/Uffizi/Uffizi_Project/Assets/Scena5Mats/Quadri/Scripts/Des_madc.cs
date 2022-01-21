using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_madc : MonoBehaviour
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
                        testo.text = "Quest’opera non finita appartenente alla maturità del Pontormo, fu riscoperta nel 1907 grazie al fine \nconoscitore Carlo Gamba.Venne rinvenuta all’interno dei depositi delle gallerie fiorentine dove la sfortuna critica \ndel suo autore aveva finito per relegarla. Il quadro, che in passato fu interpretato come una raffigurazione della\nCarità, in virtù di quel trasporto d’affetto umanissimo che lega la donna ai due fanciulli, colpisce per l’inquieto \nbattito della luce e il drammatico incupirsi delle ombre, che rimandano quasi fatalmente alla futura deposizione di\nCristo.La vivacità dei colori tipica del Pontormo contribuisce a conferire un’atmosfera surreale all’intera\ncomposizione, la quale acquisisce un’aura sognante da ribalta di teatro. Nel dipinto si nota un consapevole e\nsensibile recupero della maniera leonardesca, sulla quale l’artista innesta un modo di costruire i volumi dei corpi\nderivatogli dal Michelangelo della Volta della Sistina. Proprio a Buonarroti il Pontormo sembra riferirsi nell’uso\ndel colore puro per restituire l’avanzare e il retrocedere dei corpi. La possente Madonna dalla fisicità\nmichelangiolesca, si curva avanti ad abbracciare Gesù Bambino, seduto sulle sue ginocchia, e San Giovannino,\nche si protende da destra. Anche la torsione del corpo e l’espressione patetica di San Giovannino sembrano\nrimandare a opere di Michelangelo di quegli anni come la Madonna Medici, così come lo sporgere della gamba del\nBambino.L’incompiutezza dell’opera potrebbe essere dovuta alla effettiva coincidenza coi tempi dell’assedio di\nFirenze(dall’ottobre del 1529 all’agosto del 1530).Tempi che furono duri da sopportare per tutti i fiorentini, e che\nverosimilmente incisero sull’animo vibratile del Pontormo, tanto da portarlo ad esasperare, nella sua produzione,\nforme e gamma cromatica e luministica.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "This unfinished work, belonging to the maturity of Pontormo, was rediscovered in 1907 thanks to the end \nconnoisseur Carlo Gamba. It was found inside the deposits of the Florentine galleries where the unfortunate criticism \nof its author had ended up relegating it. The painting, which in the past was interpreted as a representation of \nCharity, by virtue of that transport of human affection that binds the woman to the two children, strikes for the \nrestless beat of light and the dramatic incuperation of shadows, which almost fatally refer to the future deposition of \nChrist. The liveliness of colors typical of Pontormo helps to give a surreal atmosphere to the entire \ncomposition, which acquires a dreamy aura from the limelight of the theater. In the painting one can notice a \nconscious and sensitive recovery of Leonardo's manner, on which the artist grafts a way of constructing the volumes \nof the bodies derived from Michelangelo della Volta della Sistina. It is precisely in Buonarroti that Pontormo \nseems to refer to the use of pure colour to restore the advance and retreat of bodies. The mighty Madonna \nof Michelangelo's physicality curves forward to embrace the Child Jesus, sitting on his knees, and St. John, \nwho stretches out from the right. Even the twisting of the body and the pathetic expression of St. John \nseem to refer to Michelangelo's works of those years as the Madonna Medici, as well as the protruding leg of the \nchild. The incompleteness of the work could be due to the actual coincidence with the times of the siege of \nFlorence (from October 1529 to August 1530), times that were hard to bear for all Florentines, and that probably \nengraved on the vibrating soul of Pontormo, so as to lead him to exasperate, in his production, forms and range \nof colors and light.";
                    }
                }
            }
        }
    }
}
