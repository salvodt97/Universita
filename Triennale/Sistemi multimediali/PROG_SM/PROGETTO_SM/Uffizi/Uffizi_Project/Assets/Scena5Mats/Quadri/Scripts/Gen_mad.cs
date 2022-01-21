using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_mad : MonoBehaviour
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
                        testo.text = "Autore: Raffaello Sanzio (Urbino 1483 – Roma 1520)\nData: Entro febbraio 1506\nTecnica: Olio su tavola\nDimensioni: 107 x 77,2 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Raffaello Sanzio (Urbino 1483 – Roma 1520)\nDate: By February 1506\nTecnique: oil on wood\nSize: 107 x 77,2 cm";
                    }
                }
            }
        }
    }
}
