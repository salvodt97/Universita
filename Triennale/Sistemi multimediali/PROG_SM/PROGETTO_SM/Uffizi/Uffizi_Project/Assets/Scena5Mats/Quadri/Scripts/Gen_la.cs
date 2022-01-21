using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_la : MonoBehaviour
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
                        testo.text = "Autore: Giuseppe Maria Crespi(Bologna 1665 - 1747)\nData: 1709\nTecnica: Olio su tela\nDimensioni: 116,7 x 196,3 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Giuseppe Maria Crespi(Bologna 1665 - 1747)\nDate: 1709\nTecnique: oil on canvas\nSize: 116,7 x 196,3 cm";
                    }
                }
            }
        }
    }
}
