using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_lip : MonoBehaviour
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
                        testo.text = "Autore: Filippo Lippi(Firenze 1406 ca. – Spoleto 1469)\nData: 1460 - 1465 circa\nTecnica: Tempera su tavola\nDimensioni: 95 x 62cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Filippo Lippi(Firenze 1406 approx. – Spoleto 1469)\nDate: 1460 - 1465 approx.\nTecnique: Tempera on wood\nSize: 95 x 62cm";
                    }
                }
            }
        }
    }
}
