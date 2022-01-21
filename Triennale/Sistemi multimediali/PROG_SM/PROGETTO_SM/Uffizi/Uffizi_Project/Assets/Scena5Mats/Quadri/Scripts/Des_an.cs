using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_an : MonoBehaviour
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
                        testo.text = "Quest’opera celeberrima, raffigurante un angiolino intento a pizzicare le corde di un liuto, \nè il frammentodi una tavola d’altare andata perduta: le indagini riflettografiche hanno \nrivelato che sotto il fondo scuro, aggiunto successivamente, è raffigurata una\nparte di una struttura architettonica, ai cui piedi l’angelo musicante stava come in certe \ncomposizioni di Fra’ Bartolomeo o Raffaello.L’aspetto della composizione originale è tramandato\ndalla Sacra Conversazione dipinta intorno al 1600 da Francesco Vanni e conservata nella chiesa di\nSant’Agata ad Asciano(Siena).La riflettografia ha rivelato sotto il fondo scuro del dipinto degli Uffizi \nanche l’iscrizione con il nome dell’autore, Rosso Fiorentino, e la data 1521, ma è incerto se \nla scritta sia di mano del Rosso o non fosse piuttosto stata apposta quando la pala d’altare fu smembrata,\nallo scopo di tramandare la memoria del suo autore.Immagine tenerissima, con l’angiolino che stenta a\npadroneggiare il liuto che appare al confronto esageratamente grande, il dipinto mostra l’originale\nreinterpretazione da parte di Rosso Fiorentino di un tema tradizionale, reso particolarmente vivido da una \nstesura pittorica di grande modernità.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "This famous work, depicting an angel plucking the strings of a lute, is a fragment of an \naltarpiece that has been lost: reflective investigations have revealed that under the dark \nbackground, added later, is depicted a part of an architectural structure, at the \nfeet of which the angel musician was as in certain compositions of Fra 'Bartholomew or \nRaphael.The appearance of the original composition is handed down from the Holy Conversation painted \naround 1600 by Francesco Vanni and preserved in the church of Sant'Agata in Asciano (Siena).The \nreflectography has revealed under the dark background of the painting of the Uffizi also the inscription \nwith the name of the author, Rosso Fiorentino, and the date 1521, but it is uncertain whether \nthe inscription is by the hand of the Red or had not rather been affixed when the altarpiece was dismembered, \nin order to pass on the memory of its author.A very tender image, with the little angel struggling \nto master the lute, which appears exaggeratedly large in comparison, the painting shows Rosso \nFiorentino's original reinterpretation of a traditional theme, rendered particularly vivid by a pictorial \nlayout of great modernity";
                    }
                }
            }
        }
    }
}
