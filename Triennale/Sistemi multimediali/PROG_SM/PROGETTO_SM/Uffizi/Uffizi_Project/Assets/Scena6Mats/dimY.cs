using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class dimY : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    public void diminuisciY()
    {
        GameObject.Find("Editare").GetComponent<editareScript>().obj.transform.parent.gameObject.transform.Translate(Vector3.up * -0.5f, Space.Self);
    }
}
