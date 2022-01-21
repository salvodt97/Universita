using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class editareScript : MonoBehaviour
{
    public GameObject obj;
    public GameObject editare;
    public GameObject camminare;
    private int toggle = 0;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    public void edita()
    {
        toggle = toggle + 1;
        if (toggle % 2 == 1)
        {
            editare.SetActive(true);
            camminare.SetActive(false);
        }
        else
        {
            editare.SetActive(false);
            camminare.SetActive(true);
        }
    }

    
}
