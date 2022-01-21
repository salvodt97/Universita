using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class movimentoEditX : MonoBehaviour
{
    public GameObject sfera;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    public void movimento(float xAxis)
    {
        sfera.transform.Translate(Vector3.forward * xAxis, Space.Self);
    }
}
