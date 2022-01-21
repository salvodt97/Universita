using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_ba : MonoBehaviour
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
                        testo.text = "Autore: Michelangelo Merisi detto il Caravaggio(Milano 1571 - Porto Ercole 1610)\nData: 1598 circa\nTecnica: Olio su tela\nDimensioni: 95 x 85 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Authors: Michelangelo known as Caravaggio(Milano 1571 - Porto Ercole 1610)\nDate: 1598 approx.\nTecnique: oil on canvasa\nSize: 95 x 85 cm";
                    }
                }
            }
        }
    }
}
