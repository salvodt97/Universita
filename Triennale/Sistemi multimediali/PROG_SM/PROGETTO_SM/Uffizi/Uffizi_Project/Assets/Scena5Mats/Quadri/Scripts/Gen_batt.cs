using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Gen_batt : MonoBehaviour
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
                        testo.text = "Autori: Andrea del Verrocchio(Firenze 1435 - Venezia 1488)\n        Leonardo da Vinci(Vinci 1452 – Amboise 1519)\nData: 1475 circa\nTecnica: Tempera e olio su tavola\nDimensioni: 177 x 151 cm";
                    }
                    else if (variabile.inglese)
                    {
                        testo.text = "Authors: Andrea del Verrocchio(Firenze 1435 - Venezia 1488)\n        Leonardo da Vinci(Vinci 1452 – Amboise 1519)\nDate: 1475 approx.\nTecnique: Tempera and oil on wood\nSize: 177 x 151 cm";
                    }
                }
            }
        }
    }
}
