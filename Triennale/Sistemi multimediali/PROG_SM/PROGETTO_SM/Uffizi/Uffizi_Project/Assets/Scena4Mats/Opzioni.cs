using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Opzioni : MonoBehaviour
{
    public GameObject canvas1;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    public void opzioni()
    {
        canvas1.SetActive(true);
        this.gameObject.transform.parent.gameObject.SetActive(false);
    }
}
