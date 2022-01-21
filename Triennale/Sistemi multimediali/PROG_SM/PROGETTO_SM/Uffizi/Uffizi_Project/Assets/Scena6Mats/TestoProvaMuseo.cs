using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class TestoProvaMuseo : MonoBehaviour
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
                testo.text = "Prova il museo";
            }
            else if (variabile.inglese)
            {
                testo.text = "Try the museum";
            }
        }
    }
}
