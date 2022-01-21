using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovimentoPlayerVR : MonoBehaviour
{
    public Transform vrCamera;
    public float toggleAngle = 15.0f;
    public bool moveForward;
    //public Rigidbody rb;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (vrCamera.eulerAngles.x>=toggleAngle && vrCamera.eulerAngles.x < 90.0f)
        {
            moveForward = true;
        }
        else
        {
            moveForward = false;
        }

        if (moveForward)
        {
            transform.Translate(Vector3.forward*0.2f,Space.Self);
            //rb.AddRelativeForce(Vector3.forward * speed);
        }

    }
}
