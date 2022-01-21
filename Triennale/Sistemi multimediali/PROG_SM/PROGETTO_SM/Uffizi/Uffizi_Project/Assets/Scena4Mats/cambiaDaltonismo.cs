using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public static class Dalt
{
    public static int tipo = 0;
}
public class cambiaDaltonismo : MonoBehaviour
{
    
    // Start is called before the first frame update
    public void cambiaDalt()
    {
        Dalt.tipo++;
    }

    // Update is called once per frame
    void Update()
    {
        if (Dalt.tipo % 4 == 0)
        {
            this.gameObject.transform.GetChild(0).GetComponent<Text>().text = "Normal";
        }
        if(Dalt.tipo % 4 == 1)
        {
            this.gameObject.transform.GetChild(0).GetComponent<Text>().text = "Protanopia";
        }
        if(Dalt.tipo % 4 == 2)
        {
            this.gameObject.transform.GetChild(0).GetComponent<Text>().text = "Deuteranopia";
        }
        if(Dalt.tipo%4 == 3)
        {
            this.gameObject.transform.GetChild(0).GetComponent<Text>().text = "Tritanopia";
        }
    }
}
