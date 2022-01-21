using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using UnityEngine.XR;

public static class Switch5
{
    public static bool toggle;
}

public class vrO2d5 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        Switch5.toggle = true;
    }

    // Update is called once per frame
    void Update()
    {
        if (Switch5.toggle)
        {
            StartCoroutine(SwitchVR5());
        }
        else
        {
            StartCoroutine(SwitchTo2D5());
        }
    }

    IEnumerator SwitchVR5()
    {
        if (String.Compare(XRSettings.loadedDeviceName, "cardboard", true) != 0)
            XRSettings.LoadDeviceByName("cardboard");
        yield return null;
        XRSettings.enabled = true;
    }

    IEnumerator SwitchTo2D5()
    {
        XRSettings.LoadDeviceByName("");
        yield return null;
    }
}
