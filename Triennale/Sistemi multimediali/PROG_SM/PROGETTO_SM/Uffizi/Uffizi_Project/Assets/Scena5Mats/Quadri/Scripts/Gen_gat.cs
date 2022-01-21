using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_gat : MonoBehaviour
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
                        testo.text = "Autore: Giorgione (Castelfranco Veneto 1477 circa - Venezia 1510)\nData: 1501 - 1502\nTecnica: Olio su tela\nDimensioni: 90x73 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Giorgione (Castelfranco Veneto 1477 approx. - Venezia 1510)\nDate: 1501 - 1502\nTecnique: oil on canvas\nSize: 90x73 cm";

                    }

                }
            }
        }
    }
}
