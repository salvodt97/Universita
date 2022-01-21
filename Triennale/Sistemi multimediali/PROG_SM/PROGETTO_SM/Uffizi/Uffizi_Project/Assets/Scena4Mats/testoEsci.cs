using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class testoEsci : MonoBehaviour
{
    public Text testo;

    private void Start()
    {
        testo = GetComponent<Text>();
        if (testo)
        {
            if (variabile.italiano)
            {
                testo.text = "Esci";
            }
            else if (variabile.inglese)
            {
                testo.text = "Quit";
            }
        }
    }
}
