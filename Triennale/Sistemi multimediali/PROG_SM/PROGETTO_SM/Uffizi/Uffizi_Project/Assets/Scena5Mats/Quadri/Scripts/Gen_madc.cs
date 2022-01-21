using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_madc : MonoBehaviour
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
                        testo.text = "Autore: Pontormo (Pontorme, Empoli 1494 – Firenze 1556)\nData: 1529 - 30 circa\nTecnica: Olio su tavola\nDimensioni: 89 x 74 cm";
                    }

                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Pontormo (Pontorme, Empoli 1494 – Firenze 1556)\nDate: 1529 - 30 approx.\nTecnique: oil on wood\nSize: 89 x 74 cm";

                    }
                }
            }
        }
    }
}
