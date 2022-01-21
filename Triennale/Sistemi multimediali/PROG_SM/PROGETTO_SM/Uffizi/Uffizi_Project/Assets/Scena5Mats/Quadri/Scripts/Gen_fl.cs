using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_fl : MonoBehaviour
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
                        testo.text = "Autore: Tiziano Vecellio(Pieve di Cadore 1488 / 90 - Venezia 1576)\nData: 1517 circa\nTecnica: Olio su tela\nDimensioni: 79,7 x 63,5 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Tiziano Vecellio(Pieve di Cadore 1488 / 90 - Venezia 1576)\nDate: 1517 approx.\nTecnique: oil on canvas\nSize: 79,7 x 63,5 cm";

                    }
                }
            }
        }
    }
}
