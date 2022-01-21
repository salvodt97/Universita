using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_sa : MonoBehaviour
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
                        testo.text = "Autore: Caravaggio(Milano 1571 – Grosseto 1610)\nData: 1603 circa\nTecnica: Olio su tela\nDimensioni: 104 x 135 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Caravaggio(Milano 1571 – Grosseto 1610)\nDate: 1603 approx\nTecnica: oil on canvas\nSize: 104 x 135 cm";
                    }
                }
             }
                
        }
    }
}
