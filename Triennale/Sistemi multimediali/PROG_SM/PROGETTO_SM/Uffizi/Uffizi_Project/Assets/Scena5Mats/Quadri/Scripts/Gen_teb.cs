using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_teb : MonoBehaviour
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
                    if (variabile.italiano == true)
                    {
                        testo.text = "Autore: Beato Angelico(Vicchio di Mugello, Firenze 1395 c. - Roma 1455)\nData: 1420 circa\nTecnica: Tempera su tavola\nDimensioni: 75 x 207 cm";
                    }
                    else if (variabile.inglese == true)
                    {
                        testo.text = "Author: Beato Angelico(Vicchio di Mugello, Firenze 1395 c. - Roma 1455)\nDate: 1420 circa\nTecnique: Tempera on wood\nSize: 75 x 207 cm";
                    }
                }
            }
        }
    }
}
