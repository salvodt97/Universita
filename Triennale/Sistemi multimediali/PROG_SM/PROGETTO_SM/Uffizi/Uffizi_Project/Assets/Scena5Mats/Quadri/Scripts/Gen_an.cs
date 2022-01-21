using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_an : MonoBehaviour
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
                        testo.text = "Autore: Rosso Fiorentino (Firenze 1494 – Parigi 1540)\nData: 1521\nTecnica: Olio su tavola\nDimensioni: 39,5 x 47 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Rosso Fiorentino (Firenze 1494 – Parigi 1540)\nDate: 1521\nTecnique: oil on wood\nSize: 39,5 x 47 cm";
                    }
                }
            }
        }
    }
}
