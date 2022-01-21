using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_giu : MonoBehaviour
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
                        testo.text = "Autore: Artemisia Gentileschi(Roma 1593 - Napoli 1652 / 53)\nData: 1620 circa\nTecnica: Olio su tela\nDimensioni: 146,5 x 108 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Artemisia Gentileschi(Roma 1593 - Napoli 1652 / 53)\nDat: 1620 approx.\nTecnique: oil on canvas\nSize: 146,5 x 108 cm";

                    }
                }
            }
        }
    }
}
