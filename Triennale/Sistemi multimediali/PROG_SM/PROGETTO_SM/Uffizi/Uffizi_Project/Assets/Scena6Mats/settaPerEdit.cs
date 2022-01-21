using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class settaPerEdit : MonoBehaviour
{
    
    // Start is called before the first frame update
    void Start()
    {

        
    }

    // Update is called once per frame
    public void Cambia()
    {
        if (GameObject.Find("Editare") != null)
        {
            GameObject go = GameObject.Find("Editare");
            go.GetComponent<editareScript>().obj = transform.parent.gameObject;
        }
    }
}
