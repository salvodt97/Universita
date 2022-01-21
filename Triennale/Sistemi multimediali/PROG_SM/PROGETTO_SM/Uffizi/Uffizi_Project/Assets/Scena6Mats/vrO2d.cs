using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using UnityEngine.XR;

public static class Switch
{
    public static bool toggle;
}

public class vrO2d : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        Switch.toggle = false;
    }

    // Update is called once per frame
    void Update()
    {
        if (Switch.toggle)
        {
            StartCoroutine(SwitchVR());
        }
        else
        {
            StartCoroutine(SwitchTo2D());
        }
    }

    IEnumerator SwitchVR()
    {
        if (String.Compare(XRSettings.loadedDeviceName, "cardboard", true) != 0)
            XRSettings.LoadDeviceByName("cardboard");
        yield return null;
        XRSettings.enabled = true;
    }

    IEnumerator SwitchTo2D()
    {
        XRSettings.LoadDeviceByName("");
        yield return null;
    }
}
