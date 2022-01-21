using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class movCamera : MonoBehaviour
{
    //public float time = 0.0f;
    public GameObject can;
    // Start is called before the first frame update
    void Start()
    {
        
    }
    // Update is called once per frame
    void Update()
    {
        //time = time + Time.deltaTime;
       // if (time < 7.0f)
       if(this.gameObject.transform.localEulerAngles.x<40)
        {
            transform.Rotate(Vector3.right * 0.1f);
            transform.Translate(Vector3.back * 0.005f);
        }

        if(this.gameObject.transform.localEulerAngles.x>39)
        {
            can.SetActive(true);
        }
    }
}
