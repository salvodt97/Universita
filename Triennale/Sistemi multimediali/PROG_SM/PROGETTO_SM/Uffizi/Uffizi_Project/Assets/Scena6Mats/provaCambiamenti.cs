using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using UnityEngine.XR;

public class provaCambiamenti : MonoBehaviour
{
    public GameObject suppEdit;
    public GameObject suppPlay;
    public GameObject sfera;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    public void prova()
    {
        Switch.toggle = true;
        suppEdit.SetActive(false);
        suppPlay.SetActive(true);
        //suppPlay.transform.position = new Vector3(15,5,10);
        sfera.transform.position = new Vector3(15, 3, 10);
    }

   
}
