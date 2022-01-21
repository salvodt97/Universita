using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_ad : MonoBehaviour
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
                        testo.text = "Autore: Filippino Lippi(Prato 1457 c. – Firenze 1504)\nData: 1496\nTecnica: Tempera grassa su tavola\nDimensioni: cm 258 x 243";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Filippino Lippi(Prato 1457 approx. – Firenze 1504)\nDate: 1496\nTecnique: fat tempera grassa on wood\nSize: cm 258 x 243";

                    }
                }
            }
        }
    }
}
