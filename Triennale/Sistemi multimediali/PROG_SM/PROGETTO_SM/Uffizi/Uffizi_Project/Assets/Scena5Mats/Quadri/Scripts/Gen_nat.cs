﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_nat : MonoBehaviour
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
                        testo.text = "Autore: Cristoforo Munari(Reggio Emilia 1667 – Pisa 1720)\nData: 1709\nTecnica: Olio su tela\nDimensioni: 74 x 128,5 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Author: Cristoforo Munari(Reggio Emilia 1667 – Pisa 1720)\nDate: 1709\nTecnique: oil on canvas\nSize: 74 x 128,5 cm";
                    }
                }
            }
        }
    }
}
