using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class TestoIntro : MonoBehaviour
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
                testo.text = "GALLERIA DEGLI UFFIZI\n BENVENUTO AL TOUR";
            }
            else if (variabile.inglese)
            {
                testo.text = "GALLERIA DEGLI UFFIZI\n WELCOME TO THE TOUR";
            }
        }
    }
}
