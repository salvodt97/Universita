using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_duc : MonoBehaviour
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
                        testo.text = "Autore: Piero della Francesca (Sansepolcro, Arezzo, 1416/17 – 1492)\nData: 1473 - 1475 circa\nTecnica: Olio su tavola\nDimensioni: 47 x 33 cm ciascuno\n";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Piero della Francesca (Sansepolcro, Arezzo, 1416/17 – 1492)\nDate: 1473 - 1475 approx.\nTecnique: oil on wood\nSize: 47 x 33 cm each\n";

                    }
                }
            }
        }
    }
}
