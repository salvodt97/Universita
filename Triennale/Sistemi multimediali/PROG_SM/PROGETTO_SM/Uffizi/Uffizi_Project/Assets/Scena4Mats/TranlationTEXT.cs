using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TranlationTEXT : MonoBehaviour
{
    [SerializeField]
    private float tempo_trascorso = 0.0f;
    
    void Update() 
    {
        tempo_trascorso = tempo_trascorso + Time.deltaTime;
        if(tempo_trascorso < 6.5f)
        {
            transform.Translate(Vector3.up * 0.7f);
        }
    }

   
}
