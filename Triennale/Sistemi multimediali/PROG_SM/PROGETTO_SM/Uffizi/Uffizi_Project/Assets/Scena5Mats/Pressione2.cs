using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Events;

public class Pressione2 : MonoBehaviour
{
    public Image imgCircle;
    public UnityEvent gvrClick;
    public float totalTime = 2;
    bool gvrStatus = false;
    public float gvrTimer;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (gvrStatus)
        {
            gvrTimer = gvrTimer + Time.deltaTime;
            imgCircle.fillAmount = gvrTimer / totalTime;
        }
        if (gvrTimer > totalTime)
        {
            GetComponent<Button>().onClick.Invoke();
            gvrTimer = 0;
        }
    }
    public void gvrOn()
    {
        gvrStatus = true;
    }
    public void gvrOff()
    {
        gvrStatus = false;
        gvrTimer = 0;
        imgCircle.fillAmount = 0;
    }
}
