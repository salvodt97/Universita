using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class movCameraDopoMenu : MonoBehaviour
{
    public float time = 0.0f;
    public GameObject can;
    // Start is called before the first frame update
    void Start()
    {
        can.SetActive(false);
    }

    // Update is called once per frame
    void hhh()
    {
        time = time + Time.deltaTime;
        if (time < 7.0f)
        {
            transform.Rotate(Vector3.right * -0.1f);
            transform.Translate(Vector3.back * -0.002f);
            transform.Translate(Vector3.down * 0.001f);
        }
    }
}
