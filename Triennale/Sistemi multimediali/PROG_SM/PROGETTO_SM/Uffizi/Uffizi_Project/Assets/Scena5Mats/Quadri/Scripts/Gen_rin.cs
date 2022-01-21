using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_rin : MonoBehaviour
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
                        testo.text = "Autore: Cesare Dandini(Firenze 1596 – 1657)\nData: 1635\nTecnica: Olio su tela\nDimensioni: 185 x 203 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Cesare Dandini(Firenze 1596 – 1657)\nDate: 1635\nTecnique: oil on canvas\nSize: 185 x 203 cm";
                    }
                }
            }
        }
    }
}
