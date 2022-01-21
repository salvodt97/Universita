using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class vaiSxScript : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    public void diminuisciIndice()
    {
        GameObject.Find("cambiaImg").GetComponent<cambiaImmagine>().indice--;
    }
}
