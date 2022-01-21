using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class TastoPausa : MonoBehaviour
{
    public GameObject menupausaUI;
    public GameObject eventsystem;
    public GameObject gvreventsystem;

    public void Pausa()
    {
        menupausaUI.SetActive(true);
        gvreventsystem.SetActive(false);
        eventsystem.SetActive(true);
        Time.timeScale = 0f;
        variabile.in_pausa = true;
    }
}
