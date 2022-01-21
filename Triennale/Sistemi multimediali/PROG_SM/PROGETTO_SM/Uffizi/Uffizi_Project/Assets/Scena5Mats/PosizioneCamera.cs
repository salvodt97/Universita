using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PosizioneCamera : MonoBehaviour
{
    public Transform pallista;
    public Vector3 offset;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.position = pallista.position +offset;
    }
}
