using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using UnityEngine.XR;

public class vr : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        StartCoroutine(SwitchVR());
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    IEnumerator SwitchVR()
    {
        if (String.Compare(XRSettings.loadedDeviceName, "cardboard", true) != 0)
            XRSettings.LoadDeviceByName("cardboard");
        yield return null;
        XRSettings.enabled = true;
    }
}
