using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Indietro : MonoBehaviour
{
    public GameObject canvas;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    public void indietro()
    {
        canvas.SetActive(true);
        this.gameObject.transform.parent.gameObject.SetActive(false);
    }
}
