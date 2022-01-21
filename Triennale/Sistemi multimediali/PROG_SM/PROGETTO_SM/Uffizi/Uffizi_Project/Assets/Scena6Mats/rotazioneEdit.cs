using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class rotazioneEdit : MonoBehaviour
{
    public GameObject suppEdit;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    public void ruota(float rotaz)
    {
        suppEdit.transform.Rotate(Vector3.down * rotaz, Space.Self);
    }
}
