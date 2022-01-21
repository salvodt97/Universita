﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class TestoApplica : MonoBehaviour
{
    public Text testo;
    // Start is called before the first frame update
    void Start()
    {
        testo = GetComponent<Text>();
        if (testo)
        {
            if (variabile.italiano)
            {
                testo.text = "Cambia quadro";
            }
            else if (variabile.inglese)
            {
                testo.text = "Change painting";
            }
        }
    }
}
