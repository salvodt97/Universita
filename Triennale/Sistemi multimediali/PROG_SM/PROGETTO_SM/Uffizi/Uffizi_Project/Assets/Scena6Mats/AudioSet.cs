using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AudioSet : MonoBehaviour
{
    public AudioSource Audio1;
    public AudioSource Audio2;
    // Start is called before the first frame update
    void Start()
    {  
        if (audioSelezione.selezione % 3 == 1)
        {
            Audio1.Play();
        }
        if(audioSelezione.selezione % 3 == 2)
        {
            Audio2.Play();
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
