using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RotazionePlayer : MonoBehaviour
{
    public Transform rotazione;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.rotation = rotazione.rotation;
        
    }
}
