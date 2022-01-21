using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Desc_ma : MonoBehaviour
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
                        testo.text = "Un documento del luglio 1481 attesta che Leonardo da Vinci aveva ricevuto dai Canonici\nregolari di Sant’ Agostino l’incarico di dipingere la tavola dell’altare maggiore della chiesa di \nSan Donato a Scopeto, situata fuori dalla cerchia muraria di Firenze.Il dipinto, che Leonardo \nsi impegnava a completare entro 30 mesi, aveva come tema l’Adorazione dei Magi, cioè la \ncelebrazione della festa dell’Epifania in cui, secondo Sant’ Agostino, tutti i popoli rispondono alla \nchiamata di Cristo. Per questo tema Leonardo studiò una composizione molto complessa, ricca \ndi figure, articolata in un semicerchio che ha per fulcro la Vergine col Bambino. Davanti si \ninginocchiano i Magi, che portano in dono a Gesù oro, incenso e mirra. Leonardo dipinge \nun fondale in cui s’avvicendano architetture rovinose, scontri di cavalli e cavalieri; a sinistra \nè raffigurata la costruzione di un edificio, forse un tempio, preceduto da due rampe di scale come \nil presbiterio di alcune chiese medievali(ad esempio San Miniato al Monte a Firenze).Il tempio, \nche allude alla pace, si contrappone alla turba di cavalieri in battaglia rappresentata sul lato \nopposto.Nel settembre del 1481 Leonardo stava ancora lavorando al dipinto, ma pochi mesi \npiù tardi il pittore lasciò Firenze per recarsi a Milano, alla corte di Ludovico il Moro, interrompendo\nl’esecuzione del dipinto per la chiesa di San Donato a Scopeto.Inutilmente gli agostiniani \nattesero che il pittore tornasse per ultimare il dipinto, fino a che decisero di affidare l’esecuzione\ndi una nuova pala d’altare con l’Adorazione dei Magi a Filippino Lippi, ultimata nel 1496. \nL’Adorazione dei Magi di Leonardo è dunque un dipinto sospeso nella sua esecuzione a \nun primo livello di abbozzo. Il maestro portò l’elaborazione dell’opera a stadi diversi: \nalcuni personaggi sono appena delineati, come per fermare un’idea, altri sono più rifiniti.\nIl cielo è costituito da una stesura a base di bianco di piombo e lapislazzulo.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "A document dated July 1481 attests that Leonardo da Vinci was commissioned by the Canons \nRegular of St. Augustine to paint the panel of the high altar of the church of San Donato a Scopeto, \nlocated outside the city walls of Florence.30 months later, the theme of the painting, which \nLeonardo undertook to complete, was the Adoration of the Magi, that is, the celebration \nof the feast of the Epiphany in which, according to St. Augustine, all peoples respond to the call \nof Christ. For this theme Leonardo studied a very complex composition, rich in figures, \narticulated in a semicircle with the Virgin and Child as its fulcrum. In front of them the Magi \nkneel and bring gold, incense and myrrh as gifts to Jesus. Leonardo painted a backdrop \nin which ruinous architectures, clashes of horses and knights alternate; on the left is the construction \nof a building, perhaps a temple, preceded by two flights of stairs such as the presbytery of \nsome medieval churches (for example San Miniato al Monte in Florence).In September 1481 Leonardo \nwas still working on the painting, but a few months later the painter left Florence to go to \nMilan, to the court of Ludovico il Moro, interrupting the execution of the painting for the \nchurch of San Donato a Scopeto. Needless to say, the Augustinians waited for the painter to return to \nfinish the painting, until they decided to entrust Filippino Lippi with the execution of a \nnew altarpiece with the Adoration of the Magi, completed in 1496. The Adoration of the Magi by Leonardo \nis therefore a painting suspended in its execution at a first level of sketch. The master \ntook the elaboration of the work to different stages: Some characters are just outlined, \nas if to stop an idea, others are more refined. The sky is made up of a drawing based \non white lead and lapis lazuli";
                    }
                }
            }
        }
    }
}
