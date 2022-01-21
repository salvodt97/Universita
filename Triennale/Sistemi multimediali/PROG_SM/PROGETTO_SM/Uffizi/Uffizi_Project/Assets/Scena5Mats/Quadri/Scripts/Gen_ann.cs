using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_ann : MonoBehaviour
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
                        testo.text = "Autore: Leonardo da Vinci (Vinci 1452 – Amboise 1519)\nData: 1472 circa\nTecnica: Olio su tavola\nDimensioni: 90 x 222 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Leonardo da Vinci (Vinci 1452 – Amboise 1519)\nDate: 1472 approx.\nTecnique: oil on wood\nSize: 90 x 222 cm";
                    }
                }
            }
        }
    }
}
