using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CopiaTransform : MonoBehaviour
{
    public GameObject copiare;
    public GameObject copiare2;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        this.gameObject.transform.position = copiare.transform.position;
        this.gameObject.transform.localEulerAngles = copiare2.transform.localEulerAngles;
        
    }
}
