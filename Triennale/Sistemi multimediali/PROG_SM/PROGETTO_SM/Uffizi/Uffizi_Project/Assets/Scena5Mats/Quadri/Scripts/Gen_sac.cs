using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_sac : MonoBehaviour
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
                        testo.text = "Autore: Lorenzo Lotto (Venezia 1480 - Loreto 1556)\nData: 1534\nTecnica: Olio su tela\nDimensioni: 69 x 87,5 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Lorenzo Lotto (Venezia 1480 - Loreto 1556)\nDate: 1534\nTecnique: oil on canvas\nSize: 69 x 87,5 cm";
                    }
                }
            }
        }
    }
}
