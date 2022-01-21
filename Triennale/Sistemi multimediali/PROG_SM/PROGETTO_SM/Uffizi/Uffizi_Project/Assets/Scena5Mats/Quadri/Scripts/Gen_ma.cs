using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_ma : MonoBehaviour
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
                        testo.text = "Autore: Leonardo da Vinci (Vinci 1452 – Amboise 1519)\nData: 1482 circa\nTecnica: Disegno a carbone, acquerello di inchiostro e olio su tavola\nDimensioni: 244 x 240 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Leonardo da Vinci (Vinci 1452 – Amboise 1519)\nDate: 1482 approx\nTecnique: Carbon drawing, ink and oil watercolour on board\nSize: 244 x 240 cm";
                    }
                }
            }
        }
    }
}
