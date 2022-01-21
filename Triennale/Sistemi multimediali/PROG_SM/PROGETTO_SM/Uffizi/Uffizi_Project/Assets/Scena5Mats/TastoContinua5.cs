using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using UnityEngine.XR;

public class TastoContinua5 : MonoBehaviour
{
    public GameObject menupausaUI;
    public GameObject suppPlay;

    public void Continua()
    {
        Switch5.toggle = true;
        suppPlay.SetActive(true);
        Time.timeScale = 1f;
        variabile.in_pausa = false;
        //StartCoroutine(SwitchVR());
        menupausaUI.SetActive(false);
    }

    IEnumerator SwitchVR()
    {
        if (String.Compare(XRSettings.loadedDeviceName, "cardboard", true) != 0)
        XRSettings.LoadDeviceByName("cardboard");
        yield return null;
        XRSettings.enabled = true;
    }
}
