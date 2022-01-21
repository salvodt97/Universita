using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_tr : MonoBehaviour
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
                        testo.text = "Autore: Domenico Veneziano(Venezia, inizio XV secolo – Firenze 1461)\nData: 1445 circa\nTecnica: Tempera su tavola\nDimensioni: 209 x 213 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Domenico Veneziano(Venezia, beginning of the 15th century – Firenze 1461)\nDate: 1445 approx\nTecnique: tempera on wood\nSize: 209 x 213 cm";
                    }
                }
            }
        }
    }
}
