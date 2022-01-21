using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TastoContinua : MonoBehaviour
{
    public GameObject menupausaUI;
    public GameObject eventsystem;
    public GameObject gvreventsystem;

    public void Continua()
    {
        menupausaUI.SetActive(false);
        gvreventsystem.SetActive(true);
        eventsystem.SetActive(false);
        Time.timeScale = 1f;
        variabile.in_pausa = false;
    }

}
