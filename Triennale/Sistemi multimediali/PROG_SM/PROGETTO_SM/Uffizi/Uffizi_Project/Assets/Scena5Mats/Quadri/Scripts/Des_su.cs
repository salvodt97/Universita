using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Des_su : MonoBehaviour
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
                        testo.text = "Firmato e datato in basso a sinistra LOTUS PICTOR 1517, il dipinto risale al periodo del primo \nsoggiorno bergamasco dell’artista dal 1514 al 1525.L’episodio, ambientato in un vasto \npaesaggio delimitato da mura fortificate “alla moderna”, è tratto dall’Antico Testamento(Daniele, XIII, 1 - 64):\nSusanna, la sposa bella e casta di Ioachim, ricco ebreo, viene insidiata da due anziani giudici del popolo \nmentre si concede un bagno nel suo giardino.Questi, nel tentativo di abusare di lei, la ricattano minacciando \ndi accusarla pubblicamente di adulterio. Solo l’intervento del profeta Daniele che interrogherà separatamente \ni due vecchi i quali, caduti in contraddizione, svelano la loro menzogna-riuscirà a dimostrare l’innocenza di\nSusanna.Nel dipinto la protagonista si è denudata ed appare inginocchiata in una posa ben paragonabile \na quella della scultura della Venere accovacciata nota attraverso le copie romane dell’originale greco del \nIII secolo a.C..Con il braccio teso Susanna tiene a distanza i due anziani ed esprime la frase riportata \nsul cartiglio: Satius duco mori, quam peccare(Piuttosto che peccare, preferisco morire). Di conseguenza uno \ndei vecchioni pronuncia l’ingiusta accusa di adulterio : “Vidimus eam cum iuvene commisceri, ni nobis \nassenties testimonio nostro peribus“ (Noi siamo testimoni di averla vista unirsi con un giovane che è fuggito). I \ndue cartigli raffigurati costituiscono un diretto riferimento al testo biblico del profeta Daniele del quale il dipinto \nè la traduzione in immagini.";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Signed and dated in the lower left corner LOTUS PICTOR 1517, the painting dates back to the period \nof the artist's first stay in Bergamo from 1514 to 1525.The episode, set in a vast \nlandscape bordered by fortified walls in the modern style, is taken from the Old Testament (Daniel, XIII, 1 - 64): \nSusanna, the beautiful and chaste bride of Joachim, rich Jew, is threatened by two elderly judges of the people \nwhile taking a bath in his garden, in an attempt to abuse her, threatening to blackmail her to publicly \naccuse her of adultery. Only the intervention of the prophet Daniel, who will separately question the two \nold men -who, having fallen into contradiction, reveal their lies- will be able to prove Susanna's innocence.In \nthe painting, the protagonist has stripped herself bare and appears to be kneeling in a pose well \ncomparable to that of the sculpture of Venus crouching known through the Roman copies of the Greek original of \nthe third century BC. With her arm outstretched, Susanna keeps the two elders at a distance and expresses \nthe phrase on the cartouche: Satius duco mori, quam peccare(Rather than sinning, I prefer to die). \nConsequently, one of the old men pronounces the unjust accusation of adultery: Vidimus eam cum iuvene commisceri, \nni nobis assenties testimonio nostro peribus (We are witnesses of having seen her join a young man who has fled). \nThe two scrolls depicted are a direct reference to the biblical text of the prophet Daniel of which the painting is \nthe translation into images";
                    }
                }
            }
        }
    }
}
