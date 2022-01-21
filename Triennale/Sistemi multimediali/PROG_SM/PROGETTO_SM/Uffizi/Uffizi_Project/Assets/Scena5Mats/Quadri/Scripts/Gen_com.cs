using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_com : MonoBehaviour
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
                        testo.text = "Autore: Giovanni Bellini(Venezia, documentato dal 1459 al 1516)\nData: 1485 – 1495 circa\nTecnica: Olio su tavola\nDimensioni: 73 x 119 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Giovanni Bellini(Venezia, documented from 1459 al 1516)\nDate: 1485 – 1495 approx.\nTecnique: oil on wood\nSize: 73 x 119 cm";

                    }
                }
            }
        }
    }
}
