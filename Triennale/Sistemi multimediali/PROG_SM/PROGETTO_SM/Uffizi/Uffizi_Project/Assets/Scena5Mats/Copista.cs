using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Copista : MonoBehaviour
{
    public Transform trasformista;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.position = trasformista.position;
    }
}
