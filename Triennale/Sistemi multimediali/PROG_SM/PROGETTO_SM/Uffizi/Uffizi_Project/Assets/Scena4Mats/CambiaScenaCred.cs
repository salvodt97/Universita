using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class CambiaScenaCred : MonoBehaviour
{
    public void cambiaScenaCred()
    {
        if (variabile.italiano)
        {
            SceneManager.LoadScene("7. Credits");
        }
        else if (variabile.inglese)
        {
            SceneManager.LoadScene("8. CreditsEN");
        }
    }
}
