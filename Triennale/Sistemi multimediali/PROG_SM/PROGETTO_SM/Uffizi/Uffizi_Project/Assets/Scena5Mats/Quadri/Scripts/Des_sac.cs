using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_sac : MonoBehaviour
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
                    if (variabile.italiano)
                    {
                        testo.text = "Il dipinto, proveniente dalla celebre raccolta del Gran Principe Ferdinando de’ Medici, reca sul lato \ndestro, alla base del cuscino sul quale riposano Sant’Anna e la Vergine l’iscrizione: “Lorenzo Loto 1534”.\nE’ una delle prime prove realizzata pochi mesi dopo l’arrivo nelle Marche di Lorenzo Lotto; con la sua \ndata(1534) costituisce un punto fermo nella ricostruzione dell’attività artistica del pittore lungo il corso del \nquarto decennio del XVI secolo.All’interno della camera da letto della Vergine le sacre figure sono rappresentate \nin modo diretto, toccante, secondo un approccio originale mediato dalla pittura fiamminga, al pari di altri dipinti\ncoevi dell’artista, come l’Annunciazione di Recanati.Anche dal punto di vista iconografico la tela si distingue \nper la sua originalità: Sant’Anna è appoggiata al gradino del letto a baldacchino, con le gambe stese e aperte \nad accogliere la Madonna e il piccolo Gesù, rappresentando così, in maniera singolarmente icastica,\nil concetto di discendenza dal suo grembo. La presenza di San Girolamo sul lato sinistro che indica con la mano\naperta la Sacra Famiglia può essere messa in relazione a un possibile committente dell’opera di nome Girolamo.\nLa gamma dei colori acidi, la gradazione della luce fredda e le ombre non molto contrastate, confermano le\ncaratteristiche delle opere lottesche di quegli anni, come la “Sacra famiglia con Santa Caterina d’Alessandria”\ndell’Accademia Carrara di Bergamo firmata e datata 1533.Una versione dello stesso dipinto(ma eseguita \nin collaborazione con la bottega) è conservata a Londra nella Courtauld Gallery, essa risulta del tutto simile \nalla nostra opera tranne che per la presenza di un brano di paesaggio in luogo del San Girolamo.Il dipinto,\nproveniente dalla celebre raccolta del Gran Principe Ferdinando de’ Medici, reca sul lato destro, alla base \ndel cuscino sul quale riposano Sant’Anna e la Vergine l’iscrizione: Lorenzo Loto 1534.E’ una delle prime prove\nrealizzata pochi mesi dopo l’arrivo nelle Marche di Lorenzo Lotto; con la sua data(1534) costituisce un punto fermo\nnella ricostruzione dell’attività artistica del pittore lungo il corso del quarto decennio del XVI secolo.All’interno \ndella camera da letto della Vergine le sacre figure sono rappresentate in modo diretto, toccante, secondo un\napproccio originale mediato dalla pittura fiamminga, al pari di altri dipinti coevi dell’artista, come \nl’Annunciazione di Recanati.La gamma dei colori acidi, la gradazione della luce fredda e le ombre non molto\ncontrastate, confermano le caratteristiche delle opere lottesche di quegli anni.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "The painting, which comes from the famous collection of the Grand Prince Ferdinando de' Medici, bears on \nthe right side, at the base of the cushion on which Saint Anne and the Virgin rest, the inscription: \nLorenzo Loto 1534.\n It is one of the first tests carried out a few months after Lorenzo Lotto's arrival in \nthe Marches; with his date (1534) it is a firm point in the reconstruction of the painter's artistic activity \nthroughout the fourth decade of the 16th century. Inside the Virgin's bedroom the sacred figures are represented in \na direct, touching way, according to an original approach mediated by Flemish painting, like other paintings of the \nsame period of the artist, such as the Annunciation by Recanati.Also from an iconographic point of view, the \ncanvas stands out for its originality: St. Anne is leaning on the step of the four-poster bed, with her legs \nextended and open to welcome the Madonna and the little Jesus, thus representing, in a singularly icastic \nway, the concept of descent from her womb. The presence of St. Jerome on the left side, which indicates the \nHoly Family with his open hand, can be related to a possible client of the work called Jerome. The range of \nacid colors, the degree of cold light and shadows not very contrasted, confirm the characteristics of the \nworks of those years, such as the Holy Family with St. Catherine of Alexandria of the Carrara Academy of Bergamo \nsigned and dated 1533.A version of the same painting (but executed in collaboration with the workshop) \nis kept in London in the Courtauld Gallery, it is very similar to our work except for the presence of a piece \nof landscape in place of the St. Jerome.The painting, which comes from the famous collection of the Grand \nPrince Ferdinando de' Medici, bears on the right side, at the base of the cushion on which rest St. Anne and \nthe Virgin, the inscription: Lorenzo Loto 1534. It is one of the first proofs made a few months after the arrival \nin the Marches of Lorenzo Lotto; with its date (1534) is a fixed point in the reconstruction of the artistic \nactivity of the painter during the fourth decade of the sixteenth century. Inside the Virgin's bedroom, the sacred \nfigures are represented in a direct, touching way, according to an original approach mediated by Flemish painting, \nlike other paintings of the same period of the artist, such as the Annunciation by Recanati, the \nrange of acid colours, the degree of cold light and the shadows that are not very contrasting, confirm the \ncharacteristics of the works of art of those years";
                    }
                }
            }
        }
    }
}
