using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpostamentoTesto : MonoBehaviour
{
    public float time = 0.0f;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        time = time + Time.deltaTime;
        if(transform.position.x > 0 && time> 2.5f)
        {
            transform.Translate(Vector3.left * 0.09f);
        }
        if(transform.position.x > -17 && time > 8.5f)
        {
            transform.Translate(Vector3.left * 0.09f);
        }
    }
}
