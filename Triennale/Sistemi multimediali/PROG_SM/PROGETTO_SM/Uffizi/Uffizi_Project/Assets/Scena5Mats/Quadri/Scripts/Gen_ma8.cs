using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_ma8 : MonoBehaviour
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
                        testo.text = "Autore: Bramantino (Bergamo, 1465 – Milano, 1530)\nData: 1512 - 1514 circa\nTecnica: Olio su tavola\nDimensioni: 205 x 166,5 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Bramantino (Bergamo, 1465 – Milano, 1530)\nDate: 1512 - 1514 approx.\nTecnique: oil on wood\nSize: 205 x 166,5 cm";

                    }
                }
            }
        }
    }
}
