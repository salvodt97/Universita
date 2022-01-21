using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Testo : MonoBehaviour
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
                testo.text = "SI CONSIGLIA DI ATTIVARE L'AUDIO \nAL FINE DI UN'ESPERIENZA OTTIMALE";
            }
            else if (variabile.inglese)
            {
                testo.text = "IT IS RECOMMENDED TO TURN ON THE AUDIO IN ORDER\n TO ACHIEVE THE BEST POSSIBLE EXPERIENCE";
            }
        }
    }
}
