﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System;
using UnityEngine.XR;

public class TastoPausa5 : MonoBehaviour
{
    public GameObject menupausaUI;
    public GameObject suppPlay;

    public void Pausa()
    {
        Switch5.toggle = false;
        //StartCoroutine(SwitchTo2D());
        suppPlay.SetActive(false);
        menupausaUI.SetActive(true);
        Time.timeScale = 0f;
        variabile.in_pausa = true;
    }

    IEnumerator SwitchTo2D()
    {
        XRSettings.LoadDeviceByName("");
        yield return null;
    }
}