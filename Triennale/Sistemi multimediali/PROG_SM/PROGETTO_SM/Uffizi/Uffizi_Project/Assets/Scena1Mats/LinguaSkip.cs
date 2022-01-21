using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class LinguaSkip : MonoBehaviour
{
    public Button it;
    public Button en;

    // Start is called before the first frame update
    void Start()
    {
        variabile.italiano = false;
        variabile.inglese = false;
        it.onClick.AddListener(Ita);
        en.onClick.AddListener(Eng);
    }

    // Update is called once per frame
    void Ita()
    {
        variabile.italiano = true;
        SceneManager.LoadScene("2. Audio");
    }

    void Eng()
    {
        variabile.inglese = true;
        SceneManager.LoadScene("2. Audio");
    }


}
