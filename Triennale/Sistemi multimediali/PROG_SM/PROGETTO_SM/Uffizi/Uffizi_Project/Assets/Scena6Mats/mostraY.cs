using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class mostraY : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (GameObject.Find("Editare").GetComponent<editareScript>().obj != null)
        {
            this.GetComponent<Text>().text = GameObject.Find("Editare").GetComponent<editareScript>().obj.transform.position.y.ToString();
        }
    }
}
