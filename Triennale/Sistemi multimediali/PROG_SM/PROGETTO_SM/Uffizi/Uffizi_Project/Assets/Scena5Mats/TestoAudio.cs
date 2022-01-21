using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public static class audioSelezione
{
    public static int selezione = 0;
}
public class TestoAudio : MonoBehaviour
{
    
    // Start is called before the first frame update
    public void cambiaAudio()
    {
        audioSelezione.selezione++;
    }

    // Update is called once per frame
    void Update()
    {
        if (audioSelezione.selezione % 3 == 0)
        {
            this.gameObject.transform.GetChild(0).GetComponent<Text>().text = "No Audio";
        }
        if(audioSelezione.selezione% 3 == 1)
        {
            this.gameObject.transform.GetChild(0).GetComponent<Text>().text = "Audio 1";
        }
        if (audioSelezione.selezione % 3 == 2)
        {
            this.gameObject.transform.GetChild(0).GetComponent<Text>().text = "Audio 2";
        }
    }
}
