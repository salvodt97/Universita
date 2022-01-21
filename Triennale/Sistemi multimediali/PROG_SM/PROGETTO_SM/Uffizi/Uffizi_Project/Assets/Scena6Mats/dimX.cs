using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class dimX : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    public void diminuisciZ()
    {
        GameObject.Find("Editare").GetComponent<editareScript>().obj.transform.parent.gameObject.transform.Translate(Vector3.right * 0.5f, Space.Self);
    }
}
