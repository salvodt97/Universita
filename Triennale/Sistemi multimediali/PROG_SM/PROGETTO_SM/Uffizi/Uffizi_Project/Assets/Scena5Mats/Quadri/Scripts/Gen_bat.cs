using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_bat : MonoBehaviour
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
                        testo.text = "Autore: Paolo Uccello (Pratovecchio, Arezzo 1397-1475)\nData: 1435 - 1440 circa\nTecnica: Tempera su tavola\nDimensioni: 182 x 323 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Paolo Uccello (Pratovecchio, Arezzo 1397-1475)\nDate: 1435 - 1440 approx.\nTecnique: Tempera on wood\nSize: 182 x 323 cm";

                    }
                }
            }
        }
    }
}
