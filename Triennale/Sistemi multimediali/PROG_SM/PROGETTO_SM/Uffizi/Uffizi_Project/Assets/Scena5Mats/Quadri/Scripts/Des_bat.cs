using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_bat : MonoBehaviour
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
                        testo.text = "La tavola faceva parte di un ciclo di tre dipinti che celebrava la vittoria dei \nfiorentini sulletruppe senesi e sull’alleanza guidata dal duca di Milano nella battaglia \ndi San Romano(Pisa) nel 1432.Niccolò da Tolentino, a capo dell’esercito fiorentino, \nè raffigurato mentre con l’asta colpisce e disarciona Bernardino della Carda, \nil condottiero alla guida delle truppe avversarie, mentre intorno infuria la battaglia. \nLa direzione delle aste e delle balestre, leggermente inclinate in avanti quelle impugnate \ndai soldati fiorentini, lievemente arretrate quelle degli avversari, presagisce l’esito della \nbattaglia.La tavola degli Uffizi è l’episodio centrale della sequenza narrativa, che iniziava \ncon la raffigurazione di Niccolò da Tolentino alla guida delle truppe fiorentine nel dipinto \noggi alla National Gallery di Londra e si chiudeva con l’attacco di Michelotto da Cotignola, \nalleato dei fiorentini, illustrato nel pannello del Museo del Louvre a Parigi. Il ciclo decorativo \nfu commissionato da Lionardo Bartolini Salimbeni, protagonista della vita politica \nfiorentina della prima metà del XV secolo, per il proprio palazzo a Firenze pochi anni \ndopo l’epica impresa; in origine le tavole avevano la forma arcuata nella parte \nsuperiore, per inserirsi fra le arcate di una sala coperta con volta a peducci. Gli eredi \ndi Lionardo Bartolini cedettero poi i dipinti a Lorenzo il Magnifico, che li fece collocare \nnel proprio palazzo di via Larga(l’odierno Palazzo Medici - Riccardi in via Cavour) \nfacendone modificare la forma probabilmente allo stesso Paolo Uccello, autore del ciclo pittorico, \nche firmò la tavola oggi agli Uffizi in basso a sinistra.Le integrazioni agli angoli mostrano \nla raffigurazione di fronde di arance, le mala medica emblema della famiglia Medici.Per la \nresa delle armature e dei finimenti Paolo Uccello impiegò una cospicua quantità di foglia metallica, \nche doveva originariamente conferire al dipinto grande ricchezza e brillantezza cromatica. \nVirtuoso della prospettiva, il pittore dimostra la sua abilità nella costruzione dei corpi scorciati \nche presuppongono un punto di vista dal basso, in virtù della collocazione alta delle tavole prevista\ndall’allestimento nel palazzo di Lionardo Bartolini.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "The panel was part of a cycle of three paintings that celebrated the victory of \nthe Florentines over the Sienese troops and the alliance led by the Duke of Milan in the \nbattle of San Romano (Pisa) in 1432. Niccolò da Tolentino, head of the Florentine army, \nis depicted while Bernardino della Carda, the leader of the opposing troops, \nstrikes and disarciona with the rod, while the battle rages around. The Uffizi table \nis the central episode of the narrative sequence, which began with the depiction of Niccolò \nda Tolentino leading the Florentine troops in the painting now in the National Gallery in London \nand ended with the attack of Michelotto da Cotignola, ally of the Florentines, illustrated \nin the panel of the Louvre Museum in Paris. The decorative cycle was commissioned by Lionardo \nBartolini Salimbeni, a leading figure in Florentine political life in the first half of the \nfifteenth century, for his palace in Florence a few years after the epic feat; originally the panels \nhad an arched shape at the top, to fit between the arches of a covered room with \na corbelled vault. Lionardo Bartolini's heirs then gave the paintings to Lorenzo il \nMagnifico, who had them placed in his palace in Via Larga (today's Palazzo Medici - \nRiccardi in Via Cavour), probably changing the shape to Paolo Uccello himself, author of \nthe pictorial cycle, who signed the panel today at the Uffizi in the lower left corner.The \nadditions to the corners show the depiction of orange foliage, the bad medical emblem \nof the Medici family. Paolo Uccello used a large quantity of metal leaf for the rendering of the \narmour and harnesses, which was originally intended to give the painting great richness and \nchromatic brilliance. Virtuous of perspective, the painter demonstrates his ability in the \nconstruction of the foreshortened bodies that presuppose a point of view from below, by virtue of the \nhigh position of the panels provided for by the installation in the palace of Lionardo Bartolini";
                    }
                }
            }
        }
    }
}
