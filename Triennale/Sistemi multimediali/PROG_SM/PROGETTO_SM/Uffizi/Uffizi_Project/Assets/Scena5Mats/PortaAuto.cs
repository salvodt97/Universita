using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PortaAuto : MonoBehaviour
{
    public GameObject porta1, posAperto1;
    public GameObject porta2, posAperto2;

    public float velocidade = 2;

    Vector3 posicInicP1, posicInicP2;
    int numObjDentro;
    void Start()
    {
        numObjDentro = 0;
        posicInicP1 = porta1.transform.localPosition;
        posicInicP2 = porta2.transform.localPosition;


    }

    // Update is called once per frame
    void Update()
    {
        if (numObjDentro > 0)
        {
            porta1.transform.localPosition = Vector3.Lerp(porta1.transform.localPosition, posAperto1.transform.localPosition, velocidade * Time.deltaTime);
            porta2.transform.localPosition = Vector3.Lerp(porta2.transform.localPosition, posAperto2.transform.localPosition, velocidade * Time.deltaTime);
        }
        else
        {
            porta1.transform.localPosition = Vector3.Lerp(porta1.transform.localPosition, posicInicP1, velocidade * Time.deltaTime);
            porta2.transform.localPosition = Vector3.Lerp(porta2.transform.localPosition, posicInicP2, velocidade * Time.deltaTime);
        }

    }

    void OnTriggerEnter()
    {
        numObjDentro++;
    }

    void OnTriggerExit()
    {
        numObjDentro--;
        if (numObjDentro < 0)
        {
            numObjDentro = 0;
        }
    }
}
