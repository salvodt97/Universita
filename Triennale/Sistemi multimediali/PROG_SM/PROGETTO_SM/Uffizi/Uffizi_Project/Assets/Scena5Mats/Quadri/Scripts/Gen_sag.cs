using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_sag : MonoBehaviour
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
                        testo.text = "Autore: Veronese (Verona 1528 – Venezia 1588)\nData: 1565 circa\nTecnica: Olio su tela\nDimensioni: 86 x 122 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Veronese (Verona 1528 – Venezia 1588)\nDate: 1565 approx.\nTecnque: oil on canvas\nSize: 86 x 122 cm";
                    }
                }
            }
        }
    }
}
