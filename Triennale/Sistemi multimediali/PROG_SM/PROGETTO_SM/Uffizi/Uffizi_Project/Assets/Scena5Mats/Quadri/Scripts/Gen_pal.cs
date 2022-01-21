using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_pal : MonoBehaviour
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
                        testo.text = "Autore: Sandro Botticelli(Firenze, 1445 - 1510)\nData: 1480 - 1485 circa\nTecnica: Tempera su tela\nDimensioni: 207 x 148 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Sandro Botticelli(Firenze, 1445 - 1510)\nDate: 1480 - 1485 approx.\nTecnique: tempera on canvas\nSize: 207 x 148 cm";
                    }
                }
            }
        }
    }
}
