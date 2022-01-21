using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using UnityEngine.XR;


public class TastoEdita : MonoBehaviour
{
    public GameObject menupausaUI;
    public GameObject suppPlay;
    public GameObject suppEdit;
    public GameObject faccUI;

    public void Continua()
    {
        Switch.toggle = false;
        faccUI.SetActive(true);
        

        Time.timeScale = 1f;
        variabile.in_pausa = false;
        //StartCoroutine(SwitchTo2D());
        menupausaUI.SetActive(false);

    }

    IEnumerator SwitchTo2D()
    {
        XRSettings.LoadDeviceByName("");
        yield return null;
    }
}
